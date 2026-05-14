# SocialNetwork

![C++](https://img.shields.io/badge/C++-0d1117?style=flat-square&logo=cplusplus&logoColor=58a6ff)
![Qt](https://img.shields.io/badge/Qt-0d1117?style=flat-square&logo=qt&logoColor=58a6ff)

A desktop social network simulator built in C++ with a Qt GUI. Models users, friendships, posts, and a live activity feed — all within a native windowed application.

---

### Features

- 👤 &nbsp;User creation and profile management
- 🔗 &nbsp;Friend/connection network graph
- 📝 &nbsp;Post and incoming post system
- 🖥 &nbsp;Native Qt desktop GUI (`.ui` layout)
- 📡 &nbsp;Network class modeling connections between users

---

### Getting Started

**Prerequisites:** Qt Creator or `qmake` + a C++ compiler (g++/clang++)

**1. Clone the repo**
```bash
git clone https://github.com/pauloshabtewold/SocialNetwork.git
cd SocialNetwork
```

**2. Build with qmake**
```bash
qmake network.pro
make
```

**Or open in Qt Creator:**
- File → Open Project → select `network.pro`
- Click the Run button

---

### Project Structure

```
SocialNetwork/
├── main.cpp                  # Entry point
├── user.cpp / user.h         # User model
├── post.cpp / post.h         # Post model
├── incomingPost.cpp / .h     # Incoming post handling
├── network.cpp / network.h   # Social graph logic
├── social_network.cpp        # Core network operations
├── socialnetworkwindow.cpp   # Qt main window
├── socialnetwork.ui          # Qt Designer UI layout
└── network.pro                   # Qt project file
```

---

### Built by [Paulos Habtewold](https://github.com/pauloshabtewold) · [LinkedIn](https://www.linkedin.com/in/paulos-habtewold-7b6b72235/)
