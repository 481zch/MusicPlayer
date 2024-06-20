#include "TableView.h"

TableView::TableView(QWidget *parent) : QTableView(parent) {}

void TableView::mouseMoveEvent(QMouseEvent* event) {
    int currentRow = rowAt(event->pos().y());
    emit hoverRow(currentRow);
    QTableView::mouseMoveEvent(event);
}
