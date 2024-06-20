#ifndef CUSTOMITEMDELEGATE_H
#define CUSTOMITEMDELEGATE_H

#include <QObject>
#include <QStyledItemDelegate>
#include <QPainter>
#include <QApplication>

class CustomItemDelegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    CustomItemDelegate(QObject* parent = nullptr);

    void paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const override;
};

#endif // CUSTOMITEMDELEGATE_H
