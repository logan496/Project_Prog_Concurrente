//
// Created by wolverine on 12/2/24.
//

#ifndef HUMAN_H
#define HUMAN_H

/**
 * @class Human
 *
 * @brief this class regroup all humans of the structure
 */
class Human {
public:
    /**
     *@brief constructor of the Human class
     *
     * @param abscice
     * @param intercept
     */
    Human(double abscice, double intercept)
        : abscice(abscice),
          intercept(intercept) {
    }

    virtual ~Human()= default;

    double getX() const;
    double getY() const;

    /**
     * @brief Moves the object to a new position
     *
     * @param newX The new x-coordinate or the amout to move in the x direction.
     * @param newY The new y-coordinate or the amout to move in the y direction.
     * @param isRelative If true, move by (newX, newY) relative to the current positon; of false, move to (newX, newY).
     */
    void move(double newX, double newY, bool isRelative = false);

private:
    double abscice;/** <L'abscice de chaque humain à un instant T */
    double intercept;/** <L'ordonnée de chaque humain à un instant T */

};
#endif //HUMAN_H
