#include "customitemdelegate.h"

CustomItemDelegate::CustomItemDelegate(QObject* parent): QStyledItemDelegate(parent) {}

void CustomItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    QStyleOptionViewItem opt = option;
    painter->save();
    painter->setClipRect(opt.rect);

    // 交替背景
    QColor backgroundColor = (index.row() % 2 == 0) ? QColor(250, 250, 250) : QColor(255, 255, 255);

    if (opt.state & QStyle::State_Selected) {
        backgroundColor = QColor(229, 229, 229);
    }
    painter->fillRect(opt.rect, backgroundColor);

    // 文本颜色设置
    QColor textColor = Qt::black;
    // 文本
    opt.palette.setColor(QPalette::Text, (opt.state & QStyle::State_Selected) ? Qt::white : Qt::black);
    painter->setFont(QFont("Arial", 10));
    painter->drawText(opt.rect, Qt::AlignLeft | Qt::AlignVCenter, index.model()->data(index, Qt::DisplayRole).toString());

    painter->restore();
}
