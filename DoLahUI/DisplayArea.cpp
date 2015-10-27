// SETS UP THE CONTAINERS NEEDED FOR UI DISPLAY AREA

#include "DisplayArea.h"


namespace DoLah {
    DisplayArea::DisplayArea(QWidget *parent)
        : QScrollArea(parent)
    {
        this->setGeometry(QRect(5, 70, 340, 450));
        this->setFrameStyle(QFrame::NoFrame);
        this->setWidgetResizable(true);

        initViewPort();
    }

    DisplayArea::~DisplayArea() {
    }

    void DisplayArea::initViewPort() {
        homePage = new QWidget;
        homeLayout = new QVBoxLayout(homePage);
        homeLayout->setAlignment(Qt::AlignTop);
        homeLayout->setSpacing(3);
        homeLayout->setContentsMargins(0, 0, 0, 0);

        donePage = new QWidget;
        doneLayout = new QVBoxLayout(donePage);
        doneLayout->setAlignment(Qt::AlignTop);
        doneLayout->setSpacing(3);
        doneLayout->setContentsMargins(0, 0, 0, 0);

        tagsPage = new QWidget;
        tagsLayout = new QVBoxLayout(tagsPage);
        tagsLayout->setAlignment(Qt::AlignTop);
        tagsLayout->setSpacing(3);
        tagsLayout->setContentsMargins(0, 0, 0, 0);

        tabbedView = new QStackedWidget(this);
        tabbedView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        tabbedView->addWidget(homePage);
        tabbedView->addWidget(donePage);
        tabbedView->addWidget(tagsPage);

        this->setWidget(tabbedView);
    }
}