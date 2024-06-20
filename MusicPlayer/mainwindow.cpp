#include "mainwindow.h"

// 初始化静态对象
MainWindow* MainWindow::mainwindow = nullptr;
// 初始化once_flag
std::once_flag MainWindow::m_flag;

MainWindow *MainWindow::getInstance()
{
    std::call_once(m_flag, []() { mainwindow = new MainWindow(nullptr); });
    return mainwindow;
}

void MainWindow::initialize()
{
    // 初始化本地的音乐，下载的音乐等等
    emit launchWindow();
}

void MainWindow::startLoadAnimation()
{
    // 修改样式表
    animation = new QTimer(this);
    ui->label_time_start->setText("加载中...");
    ui->label_time->setText("加载中...");
    ui->song_slider->setStyleSheet(Styles::loadingSliderStyle);
    connect(animation, &QTimer::timeout, this, &MainWindow::loadindAnimation);
    animation->start(450);
}

void MainWindow::stopLoadAnimation()
{
    // 恢复样式表
    ui->song_slider->setStyleSheet(Styles::normalSliderStyle);
    // 恢复到初始的位置
    ui->song_slider->setValue(0);
    // 关闭并且销毁定时器
    animation->stop();
    delete animation;
    animation = nullptr;
}

void MainWindow::recoverNoramlForPlayBtn()
{
    ui->btn_pauseMusic->setStyleSheet(Styles::normalPlayBtn);
    ui->btn_pauseMusic->setEnabled(true);
}

void MainWindow::recoverNormalForLastBtn()
{
    ui->btn_lastMusic->setStyleSheet(Styles::normalLastBtn);
    ui->btn_lastMusic->setEnabled(true);
}

void MainWindow::recoverNormalForNextBtn()
{
    ui->btn_nextMusic->setStyleSheet(Styles::normalNextBtn);
    ui->btn_nextMusic->setEnabled(true);
}

void MainWindow::setUnSelectedForPlayBtn()
{
    ui->btn_pauseMusic->setStyleSheet(Styles::unselectedForPlayBtn);
    ui->btn_pauseMusic->setEnabled(false);
}

void MainWindow::setUnSelectedForLastBtn()
{
    ui->btn_lastMusic->setStyleSheet(Styles::unselectedForLastBtn);
    ui->btn_lastMusic->setEnabled(false);
}

void MainWindow::setUnSelectedForNextBtn()
{
    ui->btn_nextMusic->setStyleSheet(Styles::unselectedForNextBtn);
    ui->btn_nextMusic->setEnabled(false);
}

void MainWindow::loadindAnimation()
{
    int curValue = ui->song_slider->sliderPosition();
    ui->song_slider->setSliderPosition((curValue + 23) % 100);
}

void MainWindow::setTray()
{
    // 设置托盘图标
    // 托盘图标以及对应的菜单
    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setIcon(QIcon(":/image/statusImage/logo.ico"));
    trayIcon->setVisible(true);

    QMenu *menu = new QMenu;

    QAction *quit;
    quit = new QAction("退出");
    connect(quit, &QAction::triggered, [&](){
        QCoreApplication::quit();
    });
    menu->addAction(quit);

    QAction *quit1;
    quit1 = new QAction("显示");
    connect(quit1, &QAction::triggered, [&](){
        this->showNormal();
    });
    menu->addAction(quit1);

    trayIcon->setContextMenu(menu);

    // 显示托盘图标
    trayIcon->show();
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 去除掉原先的标题栏
    this->setWindowFlag(Qt::FramelessWindowHint);
    // 去除标题栏
    ui->tabWidget->tabBar()->hide();
    isNormal = true;
    isPlayingMusic = false;
    isSliderBeingMoved = false;
    playMode = 0;
    playType = 1;
    loading = new Loading(this);

    // 确保在主窗口再显示
    QTimer::singleShot(0, this, [this]() {
        int x = (this->width() - loading->width()) / 2;
        int y = (this->height() - loading->height()) / 2;
        loading->move(x, y);
    });
    loading->hide();

    // 初始化群
    initVolume();
    initTitle();
    initPlayListView();
    initTable();
    initLyric();
    setTray();

    // 初始化动画
    showLyricAnim = new QPropertyAnimation(lyric, "geometry");
    hideLyricAnim = new QPropertyAnimation(lyric, "geometry");
    showPlayListAnim = new QPropertyAnimation(playView, "geometry");
    hidePlayListAnim = new QPropertyAnimation(playView, "geometry");

    // 设置动画持续时间
    showLyricAnim->setDuration(300);
    hideLyricAnim->setDuration(300);
    showPlayListAnim->setDuration(100);
    hidePlayListAnim->setDuration(100);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 实现双击放大和复原事件，音量slider的显示和隐藏，歌词界面显示信号的触发
// 实现对slider拖动信号的触发
bool MainWindow::eventFilter(QObject *object, QEvent *event)
{
    if (object == ui->titleWidget) {
        if (event->type() == QEvent::MouseButtonDblClick) {
            QMouseEvent* e = static_cast<QMouseEvent*>(event);
            if (e->button() == Qt::LeftButton) {
                on_btn_changeSize_clicked();
            }
        }
    }

    if (object == ui->btn_volume) {
        if (event->type() == QMouseEvent::Enter) {
            // 正常状态下音量界面出现的位置
            if(this->windowState() == Qt::WindowNoState)
            {
                volume->move(ui->btn_volume->x()-14,ui->btn_volume->y()+485);
                volume->raise();
                volume->show();
            }
            // 最大化时出现的位置
            else if(this->windowState() == Qt::MaximumSize)
            {
                volume->move(ui->btn_volume->x()-14,ui->btn_volume->y()+631);
                volume->raise();
                volume->show();
            }
        }

        // 并且鼠标不在音量进度条控件中
        if (event->type() == QMouseEvent::Leave && !volume->geometry().contains(this->mapFromGlobal(QCursor::pos()))) {
            volume->hide();
        }
    }

    if (object == volume) {
        if (event->type() == QMouseEvent::Leave) {
            volume->hide();
        }
    }

    if (object == ui->label_singer_pic && event->type() == QEvent::MouseButtonPress) {
        QMouseEvent* e = static_cast<QMouseEvent*>(event);
        if (e->button() == Qt::LeftButton && !isLyricWindow) {
            // 显示界面
            // 显示位置和显示大小
            showLyricAnimation();
        } else {
            // 隐藏界面
            hideLyricAnimation();
        }
    }

    return QMainWindow::eventFilter(object,event);
}

// 显示歌词界面的动画效果
void MainWindow::showLyricAnimation() {
    int height = ui->titleWidget->height() + ui->widget_2->height();
    int width = ui->titleWidget->width();
    QRect startRect(0, height, width, height); // 从下方开始
    QRect endRect(0, 0, width, height); // 到顶部位置

    showLyricAnim->setStartValue(startRect);
    showLyricAnim->setEndValue(endRect);
    showLyricAnim->start();

    lyric->show();
    if (playView->isVisible()) {
        isDisPlayList = false;
        playView->hide();
    }
    isLyricWindow = true;
}

// 隐藏歌词界面的动画效果
void MainWindow::hideLyricAnimation() {
    int height = ui->titleWidget->height() + ui->widget_2->height();
    int width = ui->titleWidget->width();
    QRect startRect(0, 0, width, height); // 从当前顶部位置
    QRect endRect(0, height, width, height); // 到下方位置

    hideLyricAnim->setStartValue(startRect);
    hideLyricAnim->setEndValue(endRect);
    hideLyricAnim->start();

    connect(hideLyricAnim, &QPropertyAnimation::finished, [this]() {
        lyric->hide();
        isLyricWindow = false;
    });
}

// 显示播放列表界面的动画效果
void MainWindow::showPlayListAnimation() {
    int width = 300; // 播放列表的宽度
    int height = ui->tabWidget->height(); // 播放列表的高度
    int x = ui->centralwidget->width(); // 从右下角开始
    int y = ui->titleWidget->height() + height; // 从右下角开始

    QRect startRect(x, y, width, height); // 从右下角开始
    QRect endRect(x - width, ui->titleWidget->height(), width, height); // 到左上角

    showPlayListAnim->setStartValue(startRect);
    showPlayListAnim->setEndValue(endRect);
    showPlayListAnim->start();

    playView->raise();
    playView->show();
    isDisPlayList = true;
}

// 隐藏播放列表界面的动画效果
void MainWindow::hidePlayListAnimation() {
    int width = 300; // 播放列表的宽度
    int height = ui->tabWidget->height(); // 播放列表的高度
    int x = ui->centralwidget->width() - width; // 从左上角开始
    int y = ui->titleWidget->height(); // 从左上角开始

    QRect startRect(x, y, width, height); // 从左上角开始
    QRect endRect(x + width, y + height, width, height); // 到右下角

    hidePlayListAnim->setStartValue(startRect);
    hidePlayListAnim->setEndValue(endRect);
    hidePlayListAnim->start();

    connect(hidePlayListAnim, &QPropertyAnimation::finished, [this]() {
        playView->hide();
        isDisPlayList = false;
    });
}

// 限制窗口移动发生在顶层栏
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int titleHeight = ui->titleWidget->height();
    QPoint rel = event->position().toPoint();
    QPoint cur = event->globalPosition().toPoint();

    if (event->button() == Qt::LeftButton && rel.y() < titleHeight) {
        isMoving = true;
        last = cur - this->window()->pos();
    }
    event->accept();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (isMoving && (event->buttons() & Qt::LeftButton)) {
        this->move(event->globalPosition().toPoint() - last);
    }
    event->accept();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event) {
    if (isMoving) {
        isMoving = false;
    }
    event->accept();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    emit clearCache();
    QMainWindow::closeEvent(event);
}

void MainWindow::on_btn_close_clicked()
{
    this->close();
}

void MainWindow::on_btn_min_clicked()
{
    this->showMinimized();
}

void MainWindow::on_btn_changeSize_clicked()
{
    if (isNormal) this->showMaximized();
    else  this->showNormal();

    change_btn_changeSize(isNormal);
    isNormal = !isNormal;
}

void MainWindow::change_btn_changeSize(bool state)
{
    if (state) {
        ui->btn_changeSize->setToolTip("还原");
        ui->btn_changeSize->setStyleSheet("QPushButton{"
                                          "border-image:url(:/image/titleImage/restore.png);"
                                          "border-style:hidden;"
                                          "}"

                                          "QPushButton:hover{"
                                          "border-image:url(:/image/titleImage/restoreHover.png);"
                                          "border-style:hidden;"
                                          "}");
    }
    else {
        ui->btn_changeSize->setToolTip("最大化");
        ui->btn_changeSize->setStyleSheet("QPushButton{"
                                          "border-image:url(:/image/titleImage/max.png);"
                                          "border-style:hidden;"
                                          "}"

                                          "QPushButton:hover{"
                                          "border-image:url(:/image/titleImage/maxHover.png);"
                                          "border-style:hidden;"
                                          "}");
    }
}

void MainWindow::initVolume()
{
    isMute = false;
    lastVolume = 25;
    volume = new Volume(this);
    // 安装事件过滤器
    ui->btn_volume->installEventFilter(this);
    volume->installEventFilter(this);
    volume->hide();
    // 建立连接
    connect(this, &MainWindow::changeVolume, volume, &Volume::setVolume);
    connect(volume, &Volume::curValue, this, [=](int value){curVolume = value;});
}

void MainWindow::initTitle()
{
    ui->titleWidget->installEventFilter(this);
    QAction *action = new QAction(this);
    action->setIcon(QIcon(":/image/titleImage/searchImage.png"));
    ui->search->addAction(action, QLineEdit::LeadingPosition);
}

void MainWindow::initTable()
{
    helpAddAction(ui->local_search);
    helpAddAction(ui->download_search);
    helpAddAction(ui->favorite_search);

    initTableView(ui->local_music_tableView);
    initTableView(ui->download_music_tableView);
    initTableView(playView->ui->curPlayListView);
    initTableView(ui->favorite_music_tableView);
    initTableView(ui->online_music_tableView);

    // 添加菜单
    addMenu(ui->local_music_tableView);
    addMenu(ui->download_music_tableView);
    addMenu(ui->online_music_tableView);
    // 这里面应该不需要再添加到喜欢中，应该是移除
    addMenu2(ui->favorite_music_tableView);
    addMenu1(playView->ui->curPlayListView);

    // 设置代理
    model1 = new QStandardItemModel(this);
    playView->model = new QStandardItemModel(this);

    model2 = new QStandardItemModel(this);
    model3 = new QStandardItemModel(this);
    model4 = new QStandardItemModel(this);
    QStringList header1 = {"  ", "歌曲名称", "歌手", "文件大小"};
    QStringList header2 = {"歌曲名称", "歌手"};
    setDelegateAndModel(ui->local_music_tableView, model1, header1, true);
    setDelegateAndModel(ui->download_music_tableView, model2, header1, true);
    setDelegateAndModel(ui->favorite_music_tableView, model3, header1, true);
    setDelegateAndModel(playView->ui->curPlayListView, playView->model, header2, false);
    setDelegateAndModel(ui->online_music_tableView, model4, header1, true);

    // 设置双击信号
    connect(ui->local_music_tableView, &QTableView::doubleClicked, this, [=](const QModelIndex& index){
        // 添加到播放列表头部，并且立刻开始播放当前歌曲
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        recoverNoramlForPlayBtn();
        recoverNormalForLastBtn();
        recoverNormalForNextBtn();
        emit addPlayList(data.toString());
        // 修改播放按钮样式
        isPlayingMusic = false;
        playType = 0;
        // 显式调用槽函数来触发信号
        on_btn_pauseMusic_clicked();
        playType = 1;
    });

    // 上面的对于在线音乐同样适用
    connect(ui->download_music_tableView, &QTableView::doubleClicked, this, [=](const QModelIndex& index){
        // 添加到播放列表头部，并且立刻开始播放当前歌曲
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        recoverNoramlForPlayBtn();
        recoverNormalForLastBtn();
        recoverNormalForNextBtn();
        emit addPlayList(data.toString());
        // 修改播放按钮样式
        isPlayingMusic = false;
        playType = 0;
        // 显式调用槽函数来触发信号
        on_btn_pauseMusic_clicked();
        playType = 1;
    });

    connect(ui->favorite_music_tableView, &QTableView::doubleClicked, this, [=](const QModelIndex& index){
        // 添加到播放列表头部，并且立刻开始播放当前歌曲
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        recoverNoramlForPlayBtn();
        recoverNormalForLastBtn();
        recoverNormalForNextBtn();
        emit addPlayList(data.toString());
        // 修改播放按钮样式
        isPlayingMusic = false;
        playType = 0;
        // 显式调用槽函数来触发信号
        on_btn_pauseMusic_clicked();
        playType = 1;
    });


    // 对于在播放列表中的列表项，双击后改变播放顺序，移动到首部重新播放
    connect(playView->ui->curPlayListView, &QTableView::doubleClicked, this, [=](const QModelIndex& index){
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        emit changePlaySort(data.toString());
        // 修改播放按钮样式
        isPlayingMusic = false;
        playType = 0;
        // 显式调用槽函数来触发信号
        on_btn_pauseMusic_clicked();
        playType = 1;
    });

    // 搜索音乐
    connect(ui->online_music_tableView, &QTableView::doubleClicked, this, [=](const QModelIndex& index){
        // 添加到播放列表头部，并且立刻开始播放当前歌曲
        QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
        recoverNoramlForPlayBtn();
        recoverNormalForLastBtn();
        recoverNormalForNextBtn();
        emit addPlayList(data.toString());
        // 修改播放按钮样式
        isPlayingMusic = false;
        playType = 0;
        // 显式调用槽函数来触发信号
        on_btn_pauseMusic_clicked();
        playType = 1;
    });
}

void MainWindow::helpAddAction(QLineEdit *line)
{
    QAction* action = new QAction(this);
    action->setIcon(QIcon(":/image/serach_local.png"));
    line->addAction(action, QLineEdit::LeadingPosition);
}

// 对tableView进行的通用美化
void MainWindow::initTableView(QTableView *view)
{
    // 隐藏网格线
    view->setShowGrid(false);
    // 去除纵向表头
    view->verticalHeader()->hide();
    // 去除边框
    view->setFrameShape(QFrame::NoFrame);
    // 不可编辑
    view->setEditTriggers(QAbstractItemView::NoEditTriggers);
    // 隐藏滚动条
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // 设置行选择
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    // 取消焦点
    view->setFocusPolicy(Qt::NoFocus);
    // 单元格延伸后实现单元格平分
    view->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    // 设置水平表头文字垂直居左
    view->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    // 设置垂直表头文字垂直居右
    view->verticalHeader()->setDefaultAlignment(Qt::AlignRight | Qt::AlignVCenter);
    // 设置水平表头高度
    view->horizontalHeader()->setFixedHeight(40);
    // 设置行高，与表头高度无关
    view->verticalHeader()->setDefaultSectionSize(40);
    // 设置点击表时不对水平表头进行高亮（获得焦点）
    view->horizontalHeader()->setHighlightSections(false);
    //  设置每行默认高度
    view->verticalHeader()->setDefaultSectionSize(35);
    // 开启鼠标追踪
    view->setMouseTracking(true);
    // 序号列宽度
    view->setColumnWidth(0, 15);
}

// 修改
void MainWindow::initPlayListView()
{
    isDisPlayList = false;
    playView = new PlayListView(this);
    playView->hide();
}

void MainWindow::setTableViewMenuStyle(QMenu *menu)
{
    menu->setStyleSheet(Styles::menuStyle);
}

void MainWindow::addMenu(QTableView *view)
{
    // 自定义右击菜单
    view->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(view, &QTableView::customContextMenuRequested, [this, view](const QPoint& pos) {
        QMenu menu;
        QModelIndex index = view->indexAt(pos);
        // 进行美化
        setTableViewMenuStyle(&menu);

        menu.addAction("添加到我喜欢的音乐", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            qDebug() << "发出信号";
            emit addFavoiteList(data.toString());
            emit refreshMyFavoriteMusic();
        });
        menu.addAction("加入播放列表", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            recoverNoramlForPlayBtn();
            recoverNormalForLastBtn();
            recoverNormalForNextBtn();
            emit addPlayList(data.toString());
        });
        menu.addAction("下载音乐到本地（尚未实现）", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            // emit addLocalMusic(data.toString());
        });

        menu.exec(view->viewport()->mapToGlobal(pos));
    });
}

// 在播放列表中
void MainWindow::addMenu1(QTableView *view)
{
    // 自定义右击菜单
    view->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(view, &QTableView::customContextMenuRequested, [this, view](const QPoint& pos) {
        QMenu menu;
        QModelIndex index = view->indexAt(pos);
        // 进行美化
        setTableViewMenuStyle(&menu);

        menu.addAction("添加到我喜欢的音乐", [this, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            qDebug() << "发出信号";
            emit addFavoiteList(data.toString());
            emit refreshMyFavoriteMusic();
        });
        menu.addAction("从播放列表中移除", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            if (model2->rowCount() == 1) {
                setUnSelectedForPlayBtn();
                setUnSelectedForLastBtn();
                setUnSelectedForNextBtn();
            }
            emit removeFromPlayList(index.row());
        });
        menu.addAction("下载音乐到本地（尚未实现）", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            // emit addLocalMusic(data.toString());
        });

        menu.exec(view->viewport()->mapToGlobal(pos));
    });
}

void MainWindow::addMenu2(QTableView *view)
{
    // 自定义右击菜单
    view->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(view, &QTableView::customContextMenuRequested, [this, view](const QPoint& pos) {
        QMenu menu;
        QModelIndex index = view->indexAt(pos);
        // 进行美化
        setTableViewMenuStyle(&menu);

        menu.addAction("从我喜欢中移除", [this, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            qDebug() << "发出信号";
            emit removeFavoiteList(data.toString());
        });
        menu.addAction("加入播放列表", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            recoverNoramlForPlayBtn();
            recoverNormalForLastBtn();
            recoverNormalForNextBtn();
            emit addPlayList(data.toString());
        });
        menu.addAction("下载音乐到本地（尚未实现）", [this, view, index]() {
            QVariant data = index.siblingAtColumn(0).data(Qt::UserRole);
            // emit addLocalMusic(data.toString());
        });

        menu.exec(view->viewport()->mapToGlobal(pos));
    });
}

// 设置委托和相关的模型，flag决定是否显示头部标题
void MainWindow::setDelegateAndModel(QTableView *view, QStandardItemModel *model, const QStringList& headers, bool flag)
{
    // 设置自定义委托
    CustomItemDelegate* delegate = new CustomItemDelegate(view);
    view->setItemDelegate(delegate);

    // 设置模型
    model->setHorizontalHeaderLabels(headers);
    view->setModel(model);
    view->horizontalHeader()->setVisible(flag);
}

void MainWindow::initLyric()
{
    // 将歌手图片加入事件过滤器
    isLyricWindow = false;
    lyric = new Lyric(this);
    connect(lyric->ui->btn_down, &QPushButton::clicked, this, &MainWindow::hideLyricAnimation);
    ui->label_singer_pic->installEventFilter(this);
    lyric->hide();
}

void MainWindow::on_btn_volume_clicked()
{
    // 改变样式表，发送信号
    if (isMute)
    {
        emit changeVolume(lastVolume);
        curVolume = lastVolume;
        ui->btn_volume->setStyleSheet(
            "QPushButton{border-image:url(:/image/statusImage/"
            "volume.png);}"
            "QPushButton:hover{border-image:url(:/image/"
            "statusImage/volume-hover.png)};");
    }
    else
    {
        lastVolume = volume->getUiValue();
        curVolume = 0;
        emit changeVolume(0);
        ui->btn_volume->setStyleSheet(
            "QPushButton{border-image:url(:/image/statusImage/"
            "novolume.png);}"
            "QPushButton:hover{border-image:url(:/image/"
            "statusImage/novolume-hover.png)}");
    }
    isMute = !isMute;
}

void MainWindow::on_import_music_clicked()
{
    QString desktopPath = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    // 只获取文件夹
    QString folderPath = QFileDialog::getExistingDirectory(this, "选择音乐文件夹（音乐外层的文件夹）", desktopPath, QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    emit chooseLocalPath(folderPath);
}


void MainWindow::on_play_song_list_clicked()
{
    if (isDisPlayList) {
        hidePlayListAnimation();
    }
    else {
        // 显示播放列表
        showPlayListAnimation();
    }
}


void MainWindow::on_btn_pauseMusic_clicked()
{
    if (isPlayingMusic) {
        ui->btn_pauseMusic->setStyleSheet("QPushButton{border-image:url(:/image/statusImage/play.png)}");
        isPlayingMusic = false;
        emit stopPlay();
    } else {
        ui->btn_pauseMusic->setStyleSheet("QPushButton{border-image:url(:/image/statusImage/pause.png)}");
        isPlayingMusic = true;
        emit playAccordingList(playType);
    }
}

void MainWindow::on_song_slider_sliderMoved(int position)
{
    isSliderBeingMoved = true;
}

void MainWindow::on_song_slider_sliderReleased()
{
    isSliderBeingMoved = false;
    emit sliderMoved(ui->song_slider->value());
}

void MainWindow::on_btn_play_mode_clicked()
{
    playMode = (playMode + 1) % 3;
    switch(playMode)
    {
    case 0:
    {
        ui->btn_play_mode->setStyleSheet("QPushButton{border-image:url(:/image/statusImage/"
                                         "shuffle.png);}"
                                         "QPushButton:hover{border-image:url(:/image/"
                                         "statusImage/shuffle_hover.png)};");
        emit changeMode(playPattern::RandomList);
        break;
    }
    case 1:
    {
        ui->btn_play_mode->setStyleSheet("QPushButton{border-image:url(:/image/statusImage/"
                                         "singleCycle.png);}"
                                         "QPushButton:hover{border-image:url(:/image/"
                                         "statusImage/singeCycle_hover.png)};");
        emit changeMode(playPattern::singleCycle);
        break;
    }
    case 2:
    {
        ui->btn_play_mode->setStyleSheet("QPushButton{border-image:url(:/image/statusImage/"
                                         "play_cycle.png);}"
                                         "QPushButton:hover{border-image:url(:/image/"
                                         "statusImage/play_cycle_hover.png)};");
        emit changeMode(playPattern::CycleList);
        break;
    }
    }
}


void MainWindow::on_btn_local_playAll_clicked()
{
    emit addListToPlayList(model1);
    // 修改播放按钮样式
    isPlayingMusic = false;
    playType = 0;
    // 显式调用槽函数来触发信号
    on_btn_pauseMusic_clicked();
    playType = 1;
}


void MainWindow::on_btn_download_playAll_clicked()
{
    emit addListToPlayList(model2);
    // 修改播放按钮样式
    isPlayingMusic = false;
    playType = 0;
    // 显式调用槽函数来触发信号
    on_btn_pauseMusic_clicked();
    playType = 1;
}


void MainWindow::on_btn_lastMusic_clicked()
{
    emit switchLastSong();
}


void MainWindow::on_btn_nextMusic_clicked()
{
    emit switchNextSong();
}


void MainWindow::on_btn_favorite_playAll_clicked()
{
    emit addListToPlayList(model3);
    // 修改播放按钮样式
    isPlayingMusic = false;
    playType = 0;
    // 显式调用槽函数来触发信号
    on_btn_pauseMusic_clicked();
    playType = 1;
}


void MainWindow::on_listwidget_local_itemClicked(QListWidgetItem *item)
{
    qDebug() << "发生了点击跳转";
    if (item->text() == "本地音乐") {
        ui->tab_5->setCurrentIndex(0);
    }
    else if (item->text() == "在线音乐") {
       ui->tab_5->setCurrentIndex(1);
    }
    else if (item->text() == "我喜欢的音乐") {
        ui->tab_5->setCurrentIndex(2);
    }
    else if (item->text() == "搜索音乐") {
        ui->tab_5->setCurrentIndex(3);
    }
}



void MainWindow::on_btn_online_playAll_clicked()
{
    emit addListToPlayList(model4);
    // 修改播放按钮样式
    isPlayingMusic = false;
    playType = 0;
    // 显式调用槽函数来触发信号
    on_btn_pauseMusic_clicked();
    playType = 1;
}

