#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include <QTableWidget>
#include <QFileDialog>
#include <QStandardPaths>
#include <QTimer>
#include <mutex>
#include <QPropertyAnimation>
#include <QStandardItemModel>
#include <QMenu>
#include <QTimer>
#include <QSystemTrayIcon>
#include "src/view/volume/volume.h"
#include "src/control/customItemDelegate/customitemdelegate.h"
#include "src/view/tableView/playlistview.h"
#include "src/view/Lyric/lyric.h"
#include "MessageStruct.h"
#include "ui_mainwindow.h"
#include "src/view/loading/loading.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static MainWindow* getInstance();
    void initialize();
    // 在播放在线音乐，缓存的过程中播放进度条动画
    void startLoadAnimation();
    void stopLoadAnimation();
    // 在没有歌曲的情况下无法播放和上一首与下一首歌曲的切换
    void recoverNoramlForPlayBtn();
    void recoverNormalForLastBtn();
    void recoverNormalForNextBtn();
    void setUnSelectedForPlayBtn();
    void setUnSelectedForLastBtn();
    void setUnSelectedForNextBtn();

protected:
    // 添加事件过滤器，实现双击窗口大小的改变事件
    virtual bool eventFilter(QObject* object, QEvent* event) override;
    // 重写窗口移动事件
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void closeEvent(QCloseEvent *event) override;

signals:
    void changeVolume(int value);
    void chooseLocalPath(const QString& localPath);
    void launchWindow();
    void addFavoiteList(const QString& songPath);
    void removeFavoiteList(const QString& songPath);
    void addPlayList(const QString& songPath);
    void changePlaySort(const QString& songPath);
    void addLocalMusic(const QString& songPath);
    void removeFromPlayList(const int& row);
    void stopPlay();
    // type为0表示不论有无播放源，立即从播放列表中拿到音乐进行播放
    // type为1表示有播放源的话，优先播放播放源，没有的情况下再按照1的方式进行播放，默认为1
    void playAccordingList(int type);
    void sliderMoved(int position);
    void clearCache();
    void changeMode(playPattern pattern);
    void addListToPlayList(QStandardItemModel* model);
    void switchLastSong();
    void switchNextSong();
    void refreshMyFavoriteMusic();

private slots:
    void on_btn_close_clicked();

    void on_btn_min_clicked();

    void on_btn_changeSize_clicked();

    void on_btn_volume_clicked();

    void on_import_music_clicked();

    void on_play_song_list_clicked();

    void on_song_slider_sliderMoved(int position);

    void on_song_slider_sliderReleased();

    void on_btn_play_mode_clicked();

    void on_btn_local_playAll_clicked();

    void on_btn_download_playAll_clicked();

    void on_btn_lastMusic_clicked();

    void on_btn_nextMusic_clicked();

    void on_btn_favorite_playAll_clicked();

    void on_listwidget_local_itemClicked(QListWidgetItem *item);

    void on_btn_online_playAll_clicked();

public slots:
    void on_btn_pauseMusic_clicked();

private:
    explicit MainWindow(QWidget *parent = nullptr);
    MainWindow(const MainWindow&) = delete;
    MainWindow& operator=(const MainWindow&) = delete;
    ~MainWindow();

private:
    // 修改最大化按钮的样式表
    void change_btn_changeSize(bool state);
    void initVolume();
    void initTitle();
    void initTable();
    void helpInitTable(QTableView* view);
    void helpAddAction(QLineEdit* line);
    void initTableView(QTableView* view);
    void initPlayListView();
    void setTableViewMenuStyle(QMenu* menu);
    void addMenu(QTableView* view);
    void addMenu1(QTableView* view);
    void addMenu2(QTableView* view);
    void setDelegateAndModel(QTableView* view, QStandardItemModel* model, const QStringList& headers, bool flag);
    void initLyric();
    void loadindAnimation(); // 具体动画的任务执行
    void setTray();
    // 显示和隐藏歌词界面的动画
    void showLyricAnimation();
    void hideLyricAnimation();
    // 显示和隐藏播放列表的动画
    void showPlayListAnimation();
    void hidePlayListAnimation();

public:
    Ui::MainWindow *ui;
    QStandardItemModel* model1; // 用于本地音乐模型
    QStandardItemModel* model2; // 用于下载音乐模型
    QStandardItemModel* model3; // 用于喜欢音乐模型
    QStandardItemModel* model4; // 用于在线音乐模型
    PlayListView* playView;
    Lyric* lyric; // 歌词界面展示
    Volume* volume;
    Loading* loading; // 加载界面
    bool isSliderBeingMoved; // 进度条是否正在移动
    int playMode; // 播放模式的状态：0.顺序播放，1.随机播放，2.单曲循环，3.列表循环
    bool isPlayingMusic; // 是否正在播放
    QTimer* animation;

private:
    static std::once_flag m_flag; // 实现单例模式
    QPoint last;
    bool isMoving;
    bool isNormal;
    bool isMute; // 是否静音
    bool isDisPlayList; // 播放列表是否正在展示
    bool isLyricWindow; // 现在是否正在展示歌词界面

    int lastVolume; // 静音前的音量大小
    int curVolume; // 当前的音量大小
    int playType;
    static MainWindow* mainwindow;
    QEventLoop *eventLoop; // 删除事件循环
    QSystemTrayIcon *trayIcon;

    // 动画属性
    QPropertyAnimation *showLyricAnim;
    QPropertyAnimation *hideLyricAnim;

    QPropertyAnimation *showPlayListAnim;
    QPropertyAnimation *hidePlayListAnim;
};
#endif // MAINWINDOW_H
