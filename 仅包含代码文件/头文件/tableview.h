#ifndef TABLEVIEW_H
#define TABLEVIEW_H

#include <QTableView>
#include <QMouseEvent>

class TableView : public QTableView {
    Q_OBJECT

public:
    explicit TableView(QWidget* parent = nullptr);

signals:
    void hoverRow(int hoverRow);

protected:
    void mouseMoveEvent(QMouseEvent* event) override;
};

#endif // TABLEVIEW_H
