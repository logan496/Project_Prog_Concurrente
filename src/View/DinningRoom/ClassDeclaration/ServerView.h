//
// Created by wolverine on 12/4/24.
//

#ifndef SERVERVIEW_H
#define SERVERVIEW_H
#include <QWidget>
#include <QLabel>
#include <queue>
#include <QVBoxLayout>

class ServerView : public QWidget {
public:
    explicit ServerView(QWidget *parent = nullptr);

private:
    QLabel *titleLabel{};
    QVBoxLayout *layout_;
};
#endif //SERVERVIEW_H
