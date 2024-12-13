#include <QApplication>
#include "MainView.h"
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"
#include "../View/commonClass/ClassDeclaration/MobileElementView.h"
#include "../Managers/classDeclaration/clientGroupManager.h"
#include "../threadPool/ThreadPool.h"
#include "../factories/DinningRoom/classDeclaration/ClientGroupFactory.h"
#include "../Models/DinningRoom/classDeclaration/ClientGroup.h"
#include "../Managers/classDeclaration/TableCreateManager.h"
#include "../factories/DinningRoom/classDeclaration/TableFactory.h"
#include "../Models/DinningRoom/classDeclaration/Table.h"
#include "../Models/DinningRoom/classDeclaration/DinningRoom.h"
#include "../Managers/classDeclaration/ManageAssignTable.h"
#include "../manageConfig/dataShared/ShareData.h"
#include "../Models/DinningRoom/classDeclaration/headWaiter.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    ShareData sharedData;
    ThreadPool pool;
    DinningRoom dinning_room;
    TableFactory table_factory;
    ClientGroupFactory client_group_factory;
    HeadWaiter head_waiter(nullptr, 200, 200);

    MobileElementView view(nullptr, &head_waiter);


    TableCreateManager table_manage(table_factory, pool, dinning_room);
    size_t taskcout = table_factory.getNumberOfTask();
    table_manage.start(taskcout);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    table_manage.stop();


    // Lancement de l'application
    ClientGroupCreator client_group_creator(sharedData);


    ClientGroupManager manager_client(client_group_factory, client_group_creator, pool);
    size_t count = client_group_creator.returnRandomClientNumber();

    Butler butler(20, 20, client_group_creator.returnRandomClientNumber(), dinning_room, sharedData);

    ManageAssignTable manage_assign_table(butler, pool, head_waiter);

    manager_client.start(count);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    MainWindow main_window(&view, &dinning_room);

    manage_assign_table.start(count);
    std::this_thread::sleep_for(std::chrono::milliseconds(10));

    manager_client.stop();
    manage_assign_table.stop();

    app.exec();

    return 0;
}
