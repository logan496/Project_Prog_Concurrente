//
// Created by wolverine on 12/2/24.
//

#ifndef CLIENTGROUPCREATOR_H
#define CLIENTGROUPCREATOR_H
#include <vector>
#include "ClientModel.h"
// #include <mutex>
// #include <condition_variable>
// #include <memory>


using namespace std;

/**
 * @class ClientGroupCreator
 *
 * @brief the generations of clients group
 */
class ClientGroupCreator : public Observable{
public:
    // /**
    //  * @brief  the constructor of the class ClientGroupCreator
    //  * @param client_group the list of the group of client shared with the butler
    //  * @param mutex_mutex
    //  * @param cv
    //  */
    // ClientGroupCreator(vector<vector<ClientModel> > &client_group, mutex &mutex_mutex,
    //                    condition_variable &cv) : sharedClientGroups(client_group),
    //                                              mutex_(mutex_mutex),
    //                                              cv(cv) {
    // };
    ClientGroupCreator(vector<vector<ClientModel>> sharedList): sharedClientGroups(sharedList) {
    } ;
    /**
     * @brief this method is used to add different clients in groups
     * @param client_group an instance of the clientModel class comming from the factory
     * @param clientNumber the number of clients in the actual group
     */
    void addClientGroup(const std::shared_ptr<ClientModel> &client_group, const int clientNumber);

    /**
     * @brief returns the number of client of a group
     * @return  @var clientNumber the number of client of the actual group
     */
    int returnRandomClientNumber() const;


private:
    vector<ClientModel> clientGroups;
    vector<vector<ClientModel> > &sharedClientGroups;
    int i = 0;
    // mutex &mutex_;
    // condition_variable &cv;
};
#endif //CLIENTGROUPCREATOR_H
