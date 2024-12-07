//
// Created by wolverine on 12/6/24.
//
#include "../Models/CommonClass/classDeclaration/MobilityModel.h"

#include <iostream>
#include <ostream>


MobilityModel::MobilityModel(): abscice(10), ordered(10) {

}

bool MobilityModel::isAtDestionAbscice(int delatX) const {
    return abscice == delatX;
}


bool MobilityModel::isAtDestinationIntercept(int delatY) const {
    return ordered == delatY;
}



// void MobilityModel::move(int deltaX, int deltaY) {
//     //while (!isAtDestionAbscice(deltaX) && !isAtDestinationIntercept(deltaY)) {
//         while (!isAtDestionAbscice(deltaX)) {
//             if (abscice > deltaX) {
//                 abscice -= 1;
//                 notify({{"x", abscice}});
//             } else if (abscice < deltaX) {
//                 abscice += 1;
//                 notify({{"x", abscice}});
//             }else {
//                 while (!isAtDestinationIntercept(deltaY)) {
//                     if (ordered > deltaY) {
//                         ordered -= 1;
//                         notify({{"y", ordered}});
//                     } else if (ordered < deltaY) {
//                         ordered += 1;
//                         notify({{"y", ordered}});
//                     }
//                 }
//             }
//         }
//     }
// //}

void MobilityModel::move(int deltaX, int deltaY) {
    while (!isAtDestionAbscice(deltaX)) {
        if (abscice > deltaX) {
            abscice -= 1;
            notify({{"x", abscice}});
        } else if (abscice < deltaX) {
            abscice += 1;
            notify({{"x", abscice}});
        }
    }

    while (!isAtDestinationIntercept(deltaY)) {
        if (ordered > deltaY) {
            ordered -= 1;
            notify({{"y", ordered}});
        } else if (ordered < deltaY) {
            ordered += 1;
            notify({{"y", ordered}});
        }
    }
}
