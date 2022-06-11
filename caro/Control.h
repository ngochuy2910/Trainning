#include "Model.h"
#include "View.h"
using namespace std;

class Control{
    private:
        Model players;

        View view;

    public:
        void AddPlayer();
        void PlayGame();
        bool CheckWin(int x ,int y);

};