#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidget>
#include <QPushButton>
#include <QTextEdit>
#include "network.h"
#include "post.h"
#include "incomingPost.h"
#include "user.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void loginButtonClicked();
    void showProfilePage(std::size_t userId);
    void goBackToProfile();
    void friendNameClicked(int row, int column);
    void suggestFriendsClicked(int row, int column);
    void addFriend();


    void laughsButton1Clicked();
    void lovesButton1Clicked();
    void hatesButton1Clicked();
    void listsLaughsButton1Clicked();
    void listsLovesButton1Clicked();
    void listsHatesButton1Clicked();

    void laughsButton2Clicked();
    void lovesButton2Clicked();
    void hatesButton2Clicked();
    void listsLaughsButton2Clicked();
    void listsLovesButton2Clicked();
    void listsHatesButton2Clicked();

    void laughsButton3Clicked();
    void lovesButton3Clicked();
    void hatesButton3Clicked();
    void listsLaughsButton3Clicked();
    void listsLovesButton3Clicked();
    void listsHatesButton3Clicked();

    void laughsButton4Clicked();
    void lovesButton4Clicked();
    void hatesButton4Clicked();
    void listsLaughsButton4Clicked();
    void listsLovesButton4Clicked();
    void listsHatesButton4Clicked();

    void laughsButton5Clicked();
    void lovesButton5Clicked();
    void hatesButton5Clicked();
    void listsLaughsButton5Clicked();
    void listsLovesButton5Clicked();
    void listsHatesButton5Clicked();

    void firstPostReactionButtonClicked();
    void secondPostReactionButtonClicked();
    void thirdPostReactionButtonClicked();
    void fourthPostReactionButtonClicked();
    void fifthPostReactionButtonClicked();


private:
    Ui::MainWindow *ui;
    Network network;
    User loggedinUser;
    User currentUser;

    QLabel* profileTitleLabel;
    QTableWidget* friendsTableWidget;
    QLabel* recentPostsLabel;
    QPushButton* backButton;
    QPushButton* addFriendButton;
    QTableWidget* friendSuggestionsTableWidget;
    QLabel* friendsLabel;
    QLabel* suggestfriendsLabel;
    QLabel* nameLabel;

    QLabel* listsLaughsLabel;
    QLabel* listsLovesLabel;
    QLabel* listsHatesLabel;
    QTableWidget* listsLaughsTable;
    QTableWidget* listsLovesTable;
    QTableWidget* listsHatesTable;

    QPushButton* laughsButton1;
    QPushButton* lovesButton1;
    QPushButton* hatesButton1;
    QPushButton* listsLaughsButton1;
    QPushButton* listsLovesButton1;
    QPushButton* listsHatesButton1;

    QPushButton* laughsButton2;
    QPushButton* lovesButton2;
    QPushButton* hatesButton2;
    QPushButton* listsLaughsButton2;
    QPushButton* listsLovesButton2;
    QPushButton* listsHatesButton2;

    QPushButton* laughsButton3;
    QPushButton* lovesButton3;
    QPushButton* hatesButton3;
    QPushButton* listsLaughsButton3;
    QPushButton* listsLovesButton3;
    QPushButton* listsHatesButton3;

    QPushButton* laughsButton4;
    QPushButton* lovesButton4;
    QPushButton* hatesButton4;
    QPushButton* listsLaughsButton4;
    QPushButton* listsLovesButton4;
    QPushButton* listsHatesButton4;

    QPushButton* laughsButton5;
    QPushButton* lovesButton5;
    QPushButton* hatesButton5;
    QPushButton* listsLaughsButton5;
    QPushButton* listsLovesButton5;
    QPushButton* listsHatesButton5;

    QPushButton* firstPostReactionButton;
    QPushButton* secondPostReactionButton;
    QPushButton* thirdPostReactionButton;
    QPushButton* fourthPostReactionButton;
    QPushButton* fifthPostReactionButton;


};

#endif
