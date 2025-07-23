#include <iostream>

using namespace std;

string specializations[20][5]{};
int regular_cnt[20]{};
int urgent_cnt[20]{};

void add_urgent(int specialization, string name)
{
    specializations[specialization][4 - urgent_cnt[specialization]] = name;
    urgent_cnt[specialization]++;
}

void add_regular(int specialization, string name)
{
    specializations[specialization][regular_cnt[specialization]] = name;
    regular_cnt[specialization]++;
}

void get_urgent(int specialization)
{
    cout << specializations[specialization][5 - urgent_cnt[specialization]] << " please go with the Dr\n";
    urgent_cnt[specialization]--;
}

void get_regular(int specialization)
{
    cout << specializations[specialization][0] << " please go with the Dr\n";
    for (int i = 1; i < regular_cnt[specialization]; i++)
    {
        specializations[specialization][i - 1] = specializations[specialization][i];
    }
    regular_cnt[specialization]--;
}

void add_patient()
{
    cout << "Enter your specialization, name, status: ";
    int specialization;
    string name;
    bool urgent;

    cin >> specialization >> name >> urgent;

    specialization--; // we represent it in 0 based index

    if (regular_cnt[specialization] + urgent_cnt[specialization] == 5)
    {
        cout << "Sorry we can't add more patients to this specialization\n";
        return;
    }

    if (urgent)
        add_urgent(specialization, name);
    else
        add_regular(specialization, name);
}

void print_patients()
{

    for (int i = 0; i < 20; i++)
    {
        if (regular_cnt[i] + urgent_cnt[i])
        {

            cout << "***********************************\n"
                 << "There are " << regular_cnt[i] + urgent_cnt[i] << " patients in specialization " << i + 1 << endl;
        }
        else
        {
            continue;
        }
        for (int j = urgent_cnt[i]; j > 0; j--)
        {
            cout << specializations[i][5 - j] << " urgent\n";
        }

        for (int j = 0; j < regular_cnt[i]; j++)
        {
            cout << specializations[i][j] << " regular\n";
        }
    }
}

void get_patient()
{
    cout << "Enter specialization: ";

    int specialization;

    cin >> specialization;
    specialization--;

    if (regular_cnt[specialization] + urgent_cnt[specialization])
    {
        if (urgent_cnt[specialization])
            get_urgent(specialization);
        else
            get_regular(specialization);
    }
    else
    {
        cout << "No Patients at the moment.Have rest, Dr\n";
    }
}

void hospital_system()
{
    while (true)
    {

        cout << "\nEnter your choice:\n"
             << "1) Add new patient\n"
             << "2) Print all patients\n"
             << "3) Get next patient\n"
             << "4) Exit\n";

        int choice;

        cin >> choice;

        if (choice == 1)
        {
            add_patient();
        }
        else if (choice == 2)
        {
            print_patients();
        }
        else if (choice == 3)
        {
            get_patient();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Please enter a valid choice\n";
        }
    }
}

int main()
{
    hospital_system();

    return 0;
}
