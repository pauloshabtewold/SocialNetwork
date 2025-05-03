#include "socialnetworkwindow.h"
#include "ui_socialnetwork.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    network.readUsers("social_network.txt");
    network.readPosts("posts.txt");
    ui->nameLabel->show();
    ui->nameTextEdit->show();

    ui->loginButton->show();
    ui->loginButton->setText("Login");


    connect(ui->loginButton, &QPushButton::clicked, this, &MainWindow::loginButtonClicked);

    ui->profileTitleLabel->setText("My Profile");
    ui->profileTitleLabel->hide();


    ui->friendsLabel->setText("Friends:");
    ui->friendsLabel->hide();


    ui->friendsTableWidget->setColumnCount(1);
    ui->friendsTableWidget->hide();


    ui->recentPostsLabel->setText("Recent Posts:");
    ui->recentPostsLabel->hide();

    ui->backButton->hide();
    ui->backButton->setText("Back");

    connect(ui->backButton, &QPushButton::clicked, this, &MainWindow::goBackToProfile);

    ui->addFriendButton->hide();
    ui->addFriendButton->setText("Add Friend");
    connect(ui->addFriendButton, &QPushButton::clicked, this, &MainWindow::addFriend);

    ui->suggestfriendsLabel->setText("Suggested Friends:");
    ui->suggestfriendsLabel->hide();
    connect(ui->friendsTableWidget, &QTableWidget::cellClicked, this, &MainWindow::friendNameClicked);

    ui->friendSuggestionsTableWidget->setColumnCount(1);
    ui->friendSuggestionsTableWidget->hide();
    connect(ui->friendSuggestionsTableWidget, &QTableWidget::cellClicked, this, &MainWindow::suggestFriendsClicked);

    ui->firstPostReactionButton->hide();
    ui->firstPostReactionButton->setText("First Post Reactions");
    connect(ui->firstPostReactionButton, &QPushButton::clicked, this, &MainWindow::firstPostReactionButtonClicked);
    ui->secondPostReactionButton->hide();
    ui->secondPostReactionButton->setText("Second Post Reactions");
    connect(ui->secondPostReactionButton, &QPushButton::clicked, this, &MainWindow::secondPostReactionButtonClicked);
    ui->thirdPostReactionButton->hide();
    ui->thirdPostReactionButton->setText("Third Post Reactions");
    connect(ui->thirdPostReactionButton, &QPushButton::clicked, this, &MainWindow::thirdPostReactionButtonClicked);
    ui->fourthPostReactionButton->hide();
    ui->fourthPostReactionButton->setText("Fourth Post Reactions");
    connect(ui->fourthPostReactionButton, &QPushButton::clicked, this, &MainWindow::fourthPostReactionButtonClicked);
    ui->fifthPostReactionButton->hide();
    ui->fifthPostReactionButton->setText("Fifth Post Reactions");
    connect(ui->fifthPostReactionButton, &QPushButton::clicked, this, &MainWindow::fifthPostReactionButtonClicked);


    ui->laughsButton1->hide();
    connect(ui->laughsButton1, &QPushButton::clicked, this, &MainWindow::laughsButton1Clicked);
    ui->lovesButton1->hide();
    connect(ui->lovesButton1, &QPushButton::clicked, this, &MainWindow::lovesButton1Clicked);
    ui->hatesButton1->hide();
    connect(ui->hatesButton1, &QPushButton::clicked, this, &MainWindow::hatesButton1Clicked);
    ui->listsLaughsButton1->hide();
    connect(ui->listsLaughsButton1, &QPushButton::clicked, this, &MainWindow::listsLaughsButton1Clicked);
    ui->listsLovesButton1->hide();
    connect(ui->listsLovesButton1, &QPushButton::clicked, this, &MainWindow::listsLovesButton1Clicked);
    ui->listsHatesButton1->hide();
    connect(ui->listsHatesButton1, &QPushButton::clicked, this, &MainWindow::listsHatesButton1Clicked);

    ui->laughsButton2->hide();
    connect(ui->laughsButton2, &QPushButton::clicked, this, &MainWindow::laughsButton2Clicked);
    ui->lovesButton2->hide();
    connect(ui->lovesButton2, &QPushButton::clicked, this, &MainWindow::lovesButton2Clicked);
    ui->hatesButton2->hide();
    connect(ui->hatesButton2, &QPushButton::clicked, this, &MainWindow::hatesButton2Clicked);
    ui->listsLaughsButton2->hide();
    connect(ui->listsLaughsButton2, &QPushButton::clicked, this, &MainWindow::listsLaughsButton2Clicked);
    ui->listsLovesButton2->hide();
    connect(ui->listsLovesButton2, &QPushButton::clicked, this, &MainWindow::listsLovesButton2Clicked);
    ui->listsHatesButton2->hide();
    connect(ui->listsHatesButton2, &QPushButton::clicked, this, &MainWindow::listsHatesButton2Clicked);

    ui->laughsButton3->hide();
    connect(ui->laughsButton3, &QPushButton::clicked, this, &MainWindow::laughsButton3Clicked);
    ui->lovesButton3->hide();
    connect(ui->lovesButton3, &QPushButton::clicked, this, &MainWindow::lovesButton3Clicked);
    ui->hatesButton3->hide();
    connect(ui->hatesButton3, &QPushButton::clicked, this, &MainWindow::hatesButton3Clicked);
    ui->listsLaughsButton3->hide();
    connect(ui->listsLaughsButton3, &QPushButton::clicked, this, &MainWindow::listsLaughsButton3Clicked);
    ui->listsLovesButton3->hide();
    connect(ui->listsLovesButton3, &QPushButton::clicked, this, &MainWindow::listsLovesButton3Clicked);
    ui->listsHatesButton3->hide();
    connect(ui->listsHatesButton3, &QPushButton::clicked, this, &MainWindow::listsHatesButton3Clicked);

    ui->laughsButton4->hide();
    connect(ui->laughsButton4, &QPushButton::clicked, this, &MainWindow::laughsButton4Clicked);
    ui->lovesButton4->hide();
    connect(ui->lovesButton4, &QPushButton::clicked, this, &MainWindow::lovesButton4Clicked);
    ui->hatesButton4->hide();
    connect(ui->hatesButton4, &QPushButton::clicked, this, &MainWindow::hatesButton4Clicked);
    ui->listsLaughsButton4->hide();
    connect(ui->listsLaughsButton4, &QPushButton::clicked, this, &MainWindow::listsLaughsButton4Clicked);
    ui->listsLovesButton4->hide();
    connect(ui->listsLovesButton4, &QPushButton::clicked, this, &MainWindow::listsLovesButton4Clicked);
    ui->listsHatesButton4->hide();
    connect(ui->listsHatesButton4, &QPushButton::clicked, this, &MainWindow::listsHatesButton4Clicked);

    ui->laughsButton5->hide();
    connect(ui->laughsButton5, &QPushButton::clicked, this, &MainWindow::laughsButton5Clicked);
    ui->lovesButton5->hide();
    connect(ui->lovesButton5, &QPushButton::clicked, this, &MainWindow::lovesButton5Clicked);
    ui->hatesButton5->hide();
    connect(ui->hatesButton5, &QPushButton::clicked, this, &MainWindow::hatesButton5Clicked);
    ui->listsLaughsButton5->hide();
    connect(ui->listsLaughsButton5, &QPushButton::clicked, this, &MainWindow::listsLaughsButton5Clicked);
    ui->listsLovesButton5->hide();
    connect(ui->listsLovesButton5, &QPushButton::clicked, this, &MainWindow::listsLovesButton5Clicked);
    ui->listsHatesButton5->hide();
    connect(ui->listsHatesButton5, &QPushButton::clicked, this, &MainWindow::listsHatesButton5Clicked);

    ui->listsLaughsLabel->setText("Users who Laughed:");
    ui->listsLovesLabel->setText("Users who Loved:");
    ui->listsHatesLabel->setText("Users who Hated:");
    ui->listsLaughsLabel->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesLabel->hide();
    ui->listsLaughsTable->hide();
    ui->listsLaughsTable->setColumnCount(1);
    ui->listsLovesTable->hide();
    ui->listsLovesTable->setColumnCount(1);
    ui->listsHatesTable->hide();
    ui->listsHatesTable->setColumnCount(1);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loginButtonClicked()
{
        QString username = ui->nameTextEdit->toPlainText();
        std::size_t userId = network.getId(username.toStdString());
        if (userId != static_cast<unsigned long>(-1)) {
            User* loggedUser = network.getUser(userId);
            loggedinUser = *loggedUser;
            showProfilePage(userId);
        }
        else {
            ui->nameTextEdit->clear();
        }
}
void MainWindow::showProfilePage(std::size_t userId)
{
    ui->listsLaughsLabel->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesLabel->hide();
    ui->listsLaughsTable->hide();
    ui->listsLovesTable->hide();
    ui->listsHatesTable->hide();
    ui->nameTextEdit->hide();
    ui->loginButton->hide();
    ui->nameLabel->hide();
    ui->profileTitleLabel->hide();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();
    ui->backButton->hide();
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->laughsButton1->hide();
    ui->lovesButton1->hide();
    ui->hatesButton1->hide();
    ui->listsLaughsButton1->hide();
    ui->listsLovesButton1->hide();
    ui->listsHatesButton1->hide();
    ui->laughsButton2->hide();
    ui->lovesButton2->hide();
    ui->hatesButton2->hide();
    ui->listsLaughsButton2->hide();
    ui->listsLovesButton2->hide();
    ui->listsHatesButton2->hide();
    ui->laughsButton3->hide();
    ui->lovesButton3->hide();
    ui->hatesButton3->hide();
    ui->listsLaughsButton3->hide();
    ui->listsLovesButton3->hide();
    ui->listsHatesButton3->hide();
    ui->laughsButton4->hide();
    ui->lovesButton4->hide();
    ui->hatesButton4->hide();
    ui->listsLaughsButton4->hide();
    ui->listsLovesButton4->hide();
    ui->listsHatesButton4->hide();
    ui->laughsButton5->hide();
    ui->lovesButton5->hide();
    ui->hatesButton5->hide();
    ui->listsLaughsButton5->hide();
    ui->listsLovesButton5->hide();
    ui->listsHatesButton5->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesLabel->hide();
    ui->listsLaughsTable->hide();
    ui->listsLovesTable->hide();
    ui->listsHatesTable->hide();

    User* user = network.getUser(userId);

    if (user) {
        currentUser = *user;
        if (userId == loggedinUser.getId()) {
            ui->profileTitleLabel->setText("My Profile");
            ui->addFriendButton->hide();
            ui->suggestfriendsLabel->show();
            ui->friendSuggestionsTableWidget->show();
            ui->backButton->hide();
            ui->profileTitleLabel->show();
            ui->friendsLabel->show();
            ui->friendsTableWidget->show();
            ui->recentPostsLabel->show();
        }
        else {
            ui->profileTitleLabel->setText(QString::fromStdString(currentUser.getName()) + "'s Profile");
            ui->addFriendButton->show();
            ui->suggestfriendsLabel->hide();
            ui-> friendSuggestionsTableWidget->hide();
            ui-> backButton->show();
            ui->profileTitleLabel->show();
            ui->friendsLabel->show();
            ui->friendsTableWidget->show();
            ui->recentPostsLabel->show();
            ui->backButton->show();
        }

        ui->friendsTableWidget->clear();
        ui->friendsTableWidget->setRowCount(currentUser.getFriends().size());
        int row = 0;

        for (std::size_t friendId : currentUser.getFriends()) {
            QTableWidgetItem* friendItem = new QTableWidgetItem(QString::fromStdString(network.getUser(friendId)->getName()));
            ui->friendsTableWidget->setItem(row, 0, friendItem);
            row++;
        }


        std::size_t score;
        std::vector<std::size_t> suggestions = network.suggestFriends(userId, score);
        ui->friendSuggestionsTableWidget->clear();
        ui->friendSuggestionsTableWidget->setRowCount(suggestions.size());
        int suggestrow = 0;

        for (std::size_t userId : suggestions) {
            QTableWidgetItem* suggestionItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
            ui->friendSuggestionsTableWidget->setItem(suggestrow, 0, suggestionItem);
            suggestrow++;
        }

        std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, userId == loggedinUser.getId());
        std::string stringposts;

        for (std::size_t i = 0; i < posts.size(); i++) {
            stringposts += posts[i]->displayPost();
            stringposts += "\n\n";
        }

        ui->recentPostsLabel->setText(QString("My Recent Posts: \n \n" ) + QString::fromStdString(stringposts));

        if (posts.size()>=1)
        {
            ui->firstPostReactionButton->show();
        }
        if (posts.size()>=2)
        {
            ui->secondPostReactionButton->show();
        }
        if (posts.size()>=3)
        {
            ui->thirdPostReactionButton->show();
        }
        if (posts.size()>=4)
        {
            ui->fourthPostReactionButton->show();
        }
        if (posts.size()==5)
        {
            ui->fifthPostReactionButton->show();
        }
    }
}



void MainWindow::goBackToProfile()
{
    showProfilePage(loggedinUser.getId());
}

void MainWindow::friendNameClicked(int row, int column) {
    User pastUser = currentUser;
    int count=0;
    for (std::size_t friendId : pastUser.getFriends()) {
        if (count==row)
        {
            currentUser = *network.getUser(friendId);
            showProfilePage(friendId);
        }
        count++;
    }
}

void MainWindow::suggestFriendsClicked(int row, int column) {
    User pastUser = currentUser;
    int count=0;
    std:: size_t score;
    for (std::size_t friendId : network.suggestFriends(pastUser.getId(), score)) {
        if (count==row)
        {
            network.addConnection(loggedinUser.getName(), network.getUser(friendId)->getName());
        }
        count++;
    }
}

void MainWindow::addFriend() {
    network.addConnection(loggedinUser.getName(), currentUser.getName());
        }

void MainWindow::laughsButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[0]->addLaugh(&loggedinUser);
}
void MainWindow::lovesButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[0]->addLove(&loggedinUser);
}
void MainWindow::hatesButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[0]->addHate(&loggedinUser);
}
void MainWindow::listsLaughsButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLaughsLabel->show();
    ui->listsLaughsTable->show();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> laughedUsers = posts[0]->getUsersWhoLaughed();
    ui->listsLaughsTable->clear();
    ui->listsLaughsTable->setRowCount(laughedUsers.size());
    int laughrow = 0;

    for (std::size_t userId : laughedUsers) {
        QTableWidgetItem* laughItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLaughsTable->setItem(laughrow, 0, laughItem);
        laughrow++;
    }
}
void MainWindow::listsLovesButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLovesLabel->show();
    ui->listsLovesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> lovedUsers = posts[0]->getUsersWhoLoved();
    ui->listsLovesTable->clear();
    ui->listsLovesTable->setRowCount(lovedUsers.size());
    int loverow = 0;

    for (std::size_t userId : lovedUsers) {
        QTableWidgetItem* loveItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLovesTable->setItem(loverow, 0, loveItem);
        loverow++;
    }
}
void MainWindow::listsHatesButton1Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsHatesLabel->show();
    ui->listsHatesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> hatedUsers = posts[0]->getUsersWhoHated();
    ui->listsHatesTable->clear();
    ui->listsHatesTable->setRowCount(hatedUsers.size());
    int haterow = 0;

    for (std::size_t userId : hatedUsers) {
        QTableWidgetItem* hateItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsHatesTable->setItem(haterow, 0, hateItem);
        haterow++;
    }
}
void MainWindow::laughsButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[1]->addLaugh(&loggedinUser);
}
void MainWindow::lovesButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[1]->addLove(&loggedinUser);
}
void MainWindow::hatesButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[1]->addHate(&loggedinUser);
}
void MainWindow::listsLaughsButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLaughsLabel->show();
    ui->listsLaughsTable->show();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> laughedUsers = posts[1]->getUsersWhoLaughed();
    ui->listsLaughsTable->clear();
    ui->listsLaughsTable->setRowCount(laughedUsers.size());
    int laughrow = 0;

    for (std::size_t userId : laughedUsers) {
        ui->firstPostReactionButton->hide();
        ui->secondPostReactionButton->hide();
        ui->thirdPostReactionButton->hide();
        ui->fourthPostReactionButton->hide();
        ui->fifthPostReactionButton->hide();
        QTableWidgetItem* laughItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLaughsTable->setItem(laughrow, 0, laughItem);
        laughrow++;
    }
}
void MainWindow::listsLovesButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLovesLabel->show();
    ui->listsLovesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> lovedUsers = posts[1]->getUsersWhoLoved();
    ui->listsLovesTable->clear();
    ui->listsLovesTable->setRowCount(lovedUsers.size());
    int loverow = 0;

    for (std::size_t userId : lovedUsers) {
        QTableWidgetItem* loveItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLovesTable->setItem(loverow, 0, loveItem);
        loverow++;
    }
}
void MainWindow::listsHatesButton2Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsHatesLabel->show();
    ui->listsHatesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> hatedUsers = posts[1]->getUsersWhoHated();
    ui->listsHatesTable->clear();
    ui->listsHatesTable->setRowCount(hatedUsers.size());
    int haterow = 0;

    for (std::size_t userId : hatedUsers) {
        QTableWidgetItem* hateItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsHatesTable->setItem(haterow, 0, hateItem);
        haterow++;
    }
}
void MainWindow::laughsButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[2]->addLaugh(&loggedinUser);
}
void MainWindow::lovesButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[2]->addLove(&loggedinUser);
}
void MainWindow::hatesButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[2]->addHate(&loggedinUser);
}
void MainWindow::listsLaughsButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLaughsLabel->show();
    ui->listsLaughsTable->show();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> laughedUsers = posts[2]->getUsersWhoLaughed();
    ui->listsLaughsTable->clear();
    ui->listsLaughsTable->setRowCount(laughedUsers.size());
    int laughrow = 0;

    for (std::size_t userId : laughedUsers) {
        QTableWidgetItem* laughItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLaughsTable->setItem(laughrow, 0, laughItem);
        laughrow++;
    }
}
void MainWindow::listsLovesButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLovesLabel->show();
    ui->listsLovesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> lovedUsers = posts[2]->getUsersWhoLoved();
    ui->listsLovesTable->clear();
    ui->listsLovesTable->setRowCount(lovedUsers.size());
    int loverow = 0;

    for (std::size_t userId : lovedUsers) {
        QTableWidgetItem* loveItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLovesTable->setItem(loverow, 0, loveItem);
        loverow++;
    }
}
void MainWindow::listsHatesButton3Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsHatesLabel->show();
    ui->listsHatesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> hatedUsers = posts[2]->getUsersWhoHated();
    ui->listsHatesTable->clear();
    ui->listsHatesTable->setRowCount(hatedUsers.size());
    int haterow = 0;

    for (std::size_t userId : hatedUsers) {
        QTableWidgetItem* hateItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsHatesTable->setItem(haterow, 0, hateItem);
        haterow++;
    }
}
void MainWindow::laughsButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[3]->addLaugh(&loggedinUser);
}
void MainWindow::lovesButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[3]->addLove(&loggedinUser);
}
void MainWindow::hatesButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[3]->addHate(&loggedinUser);
}
void MainWindow::listsLaughsButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLaughsLabel->show();
    ui->listsLaughsTable->show();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> laughedUsers = posts[3]->getUsersWhoLaughed();
    ui->listsLaughsTable->clear();
    ui->listsLaughsTable->setRowCount(laughedUsers.size());
    int laughrow = 0;

    for (std::size_t userId : laughedUsers) {
        QTableWidgetItem* laughItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLaughsTable->setItem(laughrow, 0, laughItem);
        laughrow++;
    }
}
void MainWindow::listsLovesButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLovesLabel->show();
    ui->listsLovesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> lovedUsers = posts[3]->getUsersWhoLoved();
    ui->listsLovesTable->clear();
    ui->listsLovesTable->setRowCount(lovedUsers.size());
    int loverow = 0;

    for (std::size_t userId : lovedUsers) {
        QTableWidgetItem* loveItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLovesTable->setItem(loverow, 0, loveItem);
        loverow++;
    }
}
void MainWindow::listsHatesButton4Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsHatesLabel->show();
    ui->listsHatesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> hatedUsers = posts[3]->getUsersWhoHated();
    ui->listsHatesTable->clear();
    ui->listsHatesTable->setRowCount(hatedUsers.size());
    int haterow = 0;

    for (std::size_t userId : hatedUsers) {
        QTableWidgetItem* hateItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsHatesTable->setItem(haterow, 0, hateItem);
        haterow++;
    }
}
void MainWindow::laughsButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[4]->addLaugh(&loggedinUser);
}
void MainWindow::lovesButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[4]->addLove(&loggedinUser);
}
void MainWindow::hatesButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    posts[4]->addHate(&loggedinUser);
}
void MainWindow::listsLaughsButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLaughsLabel->show();
    ui->listsLaughsTable->show();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> laughedUsers = posts[4]->getUsersWhoLaughed();
    ui->listsLaughsTable->clear();
    ui->listsLaughsTable->setRowCount(laughedUsers.size());
    int laughrow = 0;

    for (std::size_t userId : laughedUsers) {
        QTableWidgetItem* laughItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLaughsTable->setItem(laughrow, 0, laughItem);
        laughrow++;
    }
}
void MainWindow::listsLovesButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsLovesLabel->show();
    ui->listsLovesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsHatesTable->hide();
    ui->listsHatesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> lovedUsers = posts[4]->getUsersWhoLoved();
    ui->listsLovesTable->clear();
    ui->listsLovesTable->setRowCount(lovedUsers.size());
    int loverow = 0;

    for (std::size_t userId : lovedUsers) {
        QTableWidgetItem* loveItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsLovesTable->setItem(loverow, 0, loveItem);
        loverow++;
    }
}
void MainWindow::listsHatesButton5Clicked(){
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->listsHatesLabel->show();
    ui->listsHatesTable->show();
    ui->listsLaughsTable->hide();
    ui->listsLaughsLabel->hide();
    ui->listsLovesTable->hide();
    ui->listsLovesLabel->hide();
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    std::vector<std::size_t> hatedUsers = posts[4]->getUsersWhoHated();
    ui->listsHatesTable->clear();
    ui->listsHatesTable->setRowCount(hatedUsers.size());
    int haterow = 0;

    for (std::size_t userId : hatedUsers) {
        QTableWidgetItem* hateItem = new QTableWidgetItem(QString::fromStdString(network.getUser(userId)->getName()));
        ui->listsHatesTable->setItem(haterow, 0, hateItem);
        haterow++;
    }
}

void MainWindow::firstPostReactionButtonClicked(){
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->backButton->show();
    ui->profileTitleLabel->show();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();

    ui->laughsButton1->setText("Laugh");
    ui->lovesButton1->setText("Love");
    ui->hatesButton1->setText("Hate");
    ui->listsLaughsButton1->setText(QString::fromStdString(std::to_string(posts[0]->getLaughs()+1)) + " Laughed");
    ui->listsLovesButton1->setText(QString::fromStdString(std::to_string(posts[0]->getLoves()+1)) + " Loved");
    ui->listsHatesButton1->setText(QString::fromStdString(std::to_string(posts[0]->getHates()+1)) + " Hated");
    ui->laughsButton1->show();
    ui->lovesButton1->show();
    ui->hatesButton1->show();
    ui->listsLaughsButton1->show();
    ui->listsLovesButton1->show();
    ui->listsHatesButton1->show();
}
void MainWindow::secondPostReactionButtonClicked(){
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->backButton->show();
    ui->profileTitleLabel->show();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->laughsButton2->setText("Laugh");
    ui->lovesButton2->setText("Love");
    ui->hatesButton2->setText("Hate");
    ui->listsLaughsButton2->setText(QString::fromStdString(std::to_string(posts[1]->getLaughs()+1)) + " Laughed");
    ui->listsLovesButton2->setText(QString::fromStdString(std::to_string(posts[1]->getLoves()+1)) + " Loved");
    ui->listsHatesButton2->setText(QString::fromStdString(std::to_string(posts[1]->getHates()+1)) + " Hated");
    ui->laughsButton2->show();
    ui->lovesButton2->show();
    ui->hatesButton2->show();
    ui->listsLaughsButton2->show();
    ui->listsLovesButton2->show();
    ui->listsHatesButton2->show();
}
void MainWindow::thirdPostReactionButtonClicked(){
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->backButton->show();
    ui->profileTitleLabel->show();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->laughsButton3->setText("Laugh");
    ui->lovesButton3->setText("Love");
    ui->hatesButton3->setText("Hate");
    ui->listsLaughsButton3->setText(QString::fromStdString(std::to_string(posts[2]->getLaughs()+1)) + " Laughed");
    ui->listsLovesButton3->setText(QString::fromStdString(std::to_string(posts[2]->getLoves()+1)) + " Loved");
    ui->listsHatesButton3->setText(QString::fromStdString(std::to_string(posts[2]->getHates()+1)) + " Hated");
    ui->laughsButton3->show();
    ui->lovesButton3->show();
    ui->hatesButton3->show();
    ui->listsLaughsButton3->show();
    ui->listsLovesButton3->show();
    ui->listsHatesButton3->show();
}
void MainWindow::fourthPostReactionButtonClicked(){
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->backButton->show();
    ui->profileTitleLabel->show();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->laughsButton4->setText("Laugh");
    ui->lovesButton4->setText("Love");
    ui->hatesButton4->setText("Hate");
    ui->listsLaughsButton4->setText(QString::fromStdString(std::to_string(posts[3]->getLaughs()+1)) + " Laughed");
    ui->listsLovesButton4->setText(QString::fromStdString(std::to_string(posts[3]->getLoves()+1)) + " Loved");
    ui->listsHatesButton4->setText(QString::fromStdString(std::to_string(posts[3]->getHates()+1)) + " Hated");
    ui->laughsButton4->show();
    ui->lovesButton4->show();
    ui->hatesButton4->show();
    ui->listsLaughsButton4->show();
    ui->listsLovesButton4->show();
    ui->listsHatesButton4->show();
}
void MainWindow::fifthPostReactionButtonClicked(){
    std::vector<Post*> posts = network.displayPosts(currentUser.getName(), 5, currentUser.getId() == loggedinUser.getId());
    ui->addFriendButton->hide();
    ui->suggestfriendsLabel->hide();
    ui->friendSuggestionsTableWidget->hide();
    ui->backButton->show();
    ui->profileTitleLabel->show();
    ui->friendsLabel->hide();
    ui->friendsTableWidget->hide();
    ui->recentPostsLabel->hide();
    ui->firstPostReactionButton->hide();
    ui->secondPostReactionButton->hide();
    ui->thirdPostReactionButton->hide();
    ui->fourthPostReactionButton->hide();
    ui->fifthPostReactionButton->hide();
    ui->laughsButton5->setText("Laugh");
    ui->lovesButton5->setText("Love");
    ui->hatesButton5->setText("Hate");
    ui->listsLaughsButton5->setText(QString::fromStdString(std::to_string(posts[4]->getLaughs()+1)) + " Laughed");
    ui->listsLovesButton5->setText(QString::fromStdString(std::to_string(posts[4]->getLoves()+1)) + " Loved");
    ui->listsHatesButton5->setText(QString::fromStdString(std::to_string(posts[4]->getHates()+1)) + " Hated");
    ui->laughsButton5->show();
    ui->lovesButton5->show();
    ui->hatesButton5->show();
    ui->listsLaughsButton5->show();
    ui->listsLovesButton5->show();
    ui->listsHatesButton5->show();
}
