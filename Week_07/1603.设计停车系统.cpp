/*
 * @lc app=leetcode.cn id=1603 lang=cpp
 *
 * [1603] 设计停车系统
 */

// @lc code=start
class ParkingSystem
{
    int pos[3];

public:
    ParkingSystem(int big, int medium, int small)
    {
        pos[0] = big;
        pos[1] = medium;
        pos[2] = small;
    }

    bool addCar(int carType)
    {
        if (carType == 1)
        {
            if (pos[0])
            {
                pos[0]--;
                return true;
            }
        }
        else if (carType == 2)
        {
            if (pos[1])
            {
                pos[1]--;
                return true;
            }
        }
        else if (carType == 3)
        {
            if (pos[2])
            {
                pos[2]--;
                return true;
            }
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
// @lc code=end
