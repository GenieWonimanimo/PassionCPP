#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
    int bullet;
public:
    Gun(int bnum) : bullet(bnum)
    { }
    void Shot()
    {
        cout << "BBANG!" << endl;
        bullet--;
    }
    int GetBullet() const {return bullet;}
};

class Police
{
private:
    int handcuffs;
    Gun* pistol;
public:
    Police(int bnum, int bcuff)
        : handcuffs(bcuff)
    {
        if (bnum > 0)
            pistol = new Gun(bnum);
        else
            pistol = NULL;
    }
    Police(const Police& ref)
        : handcuffs(ref.handcuffs)
    {
        if (ref.pistol != NULL)
            pistol = new Gun(ref.pistol->GetBullet());
        else
            pistol = NULL;
    }
    void PutHandCuff()
    {
        cout << "SNAP!" << endl;
        handcuffs--;
    }
    void Shot()
    {
        if (pistol == NULL)
            cout << "Hut BBANG!" << endl;
        else
            pistol->Shot();
    }
    void ShowPoliceInfo()
    {
        cout << "handcuffs: " << handcuffs << endl;
        if (pistol == NULL)
            cout << "bullet: " << 0 << endl;
        else
            cout << "bullet: " << pistol->GetBullet() << endl;
    }
    Police& operator=(const Police& ref)
    {
        if (pistol != NULL)
            delete pistol;
        handcuffs = ref.handcuffs;
        if (ref.pistol != NULL)
            pistol = new Gun(ref.pistol->GetBullet());
        else
            pistol = NULL;
        return *this;
    }
    ~Police()
    {
        if (pistol != NULL)
            delete pistol;
    }
};

int main(void)
{
    Police pman(3, 5);
    Police pman2 = pman; // copy constructor
    pman.ShowPoliceInfo();
    pman2.ShowPoliceInfo();

    Police pman3(1, 2);
    pman3 = pman; // assign operator
    pman3.ShowPoliceInfo();
    return 0;
}