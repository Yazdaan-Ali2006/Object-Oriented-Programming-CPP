#include <iostream>
using namespace std;
class patient
{
protected:
    int patientid;
    string name;
    int age;
    string disease;

public:
    patient(int pid = 0, string n = "none", int a = 0, string d = "none")
    {
        patientid = pid;
        name = n;
        age = a;
        disease = d;
    }
    void inputPatient()
    {
        cout << "============ENTER PATIENT DETAILS=========" << endl;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Disease: ";
        cin >> disease;
        cout << "Enter Patient ID: ";
        cin >> patientid;
    }
    void displaypatient()
    {
        cout << "============PATIENT DEATAILS=========" << endl;
        cout << "NAME:" << name << endl;
        cout << "AGE:" << age << endl;
        cout << "DISEASE:" << disease << endl;
        cout << "PATIENT-ID" << patientid << endl;
    }
};
class doctor
{
protected:
    int doctorid;
    string name;
    string specialization;

public:
    doctor(int did = 0, string n = "none", string sp = "none")
    {
        doctorid = did;
        name = n;
        specialization = sp;
    }
    void inputDoctor()
    {
        cout << "============ENTER DOCTOR DETAILS=========" << endl;
        cout << "Enter Doctor Name: ";
        cin >> name; // Use getline(cin, name); if name has spaces
        cout << "Enter Doctor ID: ";
        cin >> doctorid;
        cout << "Enter Specialization: ";
        cin >> specialization; // Use getline(cin, specialization); for multi-word input
    }
    void displaydoctor()
    {
        cout << "DOCTOR NAME:" << name << endl;
        cout << "DOCTOR ID:" << doctorid << endl;
        cout << "DOCTOR SPECIALIZATION:" << specialization << endl;
    }
};
class appointment
{
protected:
    doctor doc;
    patient pat;
    int appointmentID;
    string date;
    string time;
    bool status;

public:
    appointment(int did = 0, string n = "none", string spcd = "none",
                int pid = 0, string np = "none", int a = 0, string d = "none",
                string t = "00", bool st = false) : doc(did, n, spcd), pat(pid, np, a, d), appointmentID(a), date(d), time(t), status(st)
    {
    }
    void bookappointment()
    {
        cout << "=======BOOK APPPOINTMENT======" << endl;
        pat.inputPatient();

        {
            cout << "============ENTER APPOINTMENT DETAILS=========" << endl;
            cout << "APPOINTMENT ID";
            cin >> appointmentID;
            cout << "Enter Date (dd/mm/yyyy): ";
            cin >> date;
            cout << "Enter Time (hh:mm): ";
            cin >> time;
        }
        doc.inputDoctor();
        cout << "STATUS: TRUE" << endl;
    }
    void displayappointment()
    {
        cout << "================APPOINTMENT DETAILS================" << endl;
        pat.displaypatient();
        cout << "APPOINTEMENT ID:" << appointmentID << endl;
        cout << "DATE:" << date << endl;
        cout << "TIME:" << time << endl;

        doc.displaydoctor();
        status = true;
    }
    int getappointmentid()
    {
        return appointmentID;
    }
};

class medicalrecord
{
protected:
    patient pat;
    int recordid;
    string diagnosis;
    string treatment;

public:
    void inputmedicalrecord()
    {
        pat.inputPatient();
        cout << "=========ENTER MEDICAL RECORDS==========" << endl;
        cout << "ENTER RECORD ID:" << endl;
        cin >> recordid;
        cout << "ENTER DIAGNOSIS:" << endl;
        cin >> diagnosis;
        cout << "ENTER TREATEMENT:" << endl;
        cin >> treatment;
    }
    void displayMedicalRecord()
    {
        cout << "=========MEDICAL RECORD DETAILS==========" << endl;
        pat.displaypatient(); // Display the patient details
        cout << "Record ID: " << recordid << endl;
        cout << "Diagnosis: " << diagnosis << endl;
        cout << "Treatment: " << treatment << endl;
    }
    int getrecordid(){
        return recordid;
    }
};
class hospital
{
protected:
    appointment appointments[10];
    medicalrecord records[10];

public:
    void addAppointment()
    {
        int choice;
        cout << "AT WHAT INDEX YOU WANT TO ADD YOUR APPOINTMENT?" << endl;
        cin >> choice;
        if (choice < 0 || choice > 9)
        {
            cout << "APPOINTMENT FAILED!" << endl;
        }
        else
        {

            appointments[choice].bookappointment();
            cout << "SUCCEEDED" << endl;
        }
    }
    void cancelAppointment()
    {

        int choice;
        cout << "ENTER YOUR ID" << endl;
        cin >> choice;
        bool a = true;
        for (int i = 0; i < 10; i++)
        {
            if (choice == appointments[i].getappointmentid())
            {
                cout << "ID FOUNDED" << endl;
                a = false;
                for (int j = i; j < 10; j++)
                {

                    appointments[j] = appointments[j + 1];
                }
                cout << "APPOINTMENT HAS BEEN DELETED" << endl;
            }
        }
        if (a)
        {
            cout << "FAILED NO ID FOUND" << endl;
        }
    }

    void showAppointments()
    {
        for (int i = 0; i < 10; i++)
        {
            if (appointments[i].getappointmentid() != 0)
                appointments[i].displayappointment();
        }
    }
    void showRecords()
    {
        for (int i = 0; i < 10; i++) 
        {          if (records[i].getrecordid()!= 0)
                        records[i].displayMedicalRecord();
          
        }
    }
    void addRecord()
    {
        int index;

        cout << "ENTER INDEX FOR RECORD (0-9): ";
        cin >> index;

        if (index < 0 || index > 9)
        {
            cout << "INVALID INDEX" << endl;
        }
        else
        {
            records[index].inputmedicalrecord();
        }
    }
};
int main()
{
    hospital h1;
    int choice;
    do
    {
        cout << "\n===== HOSPITAL MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Appointment\n";
        cout << "2. Cancel Appointment\n";
        cout << "3. Show All Appointments\n";
        cout << "4. Add Medical Record\n";
        cout << "5. Show Medical Records\n";
        cout << "6. Exit\n";
        ;
        cin >> choice;
        if (choice == 1)
        {
            h1.addAppointment();
        }
        else if (choice == 2)
        {
            h1.cancelAppointment();
        }
        else if (choice == 3)
        {
            h1.showAppointments();
        }
        else if (choice == 4)
        {
            h1.addRecord();
        }
        else if (choice == 5)
        {
            h1.showRecords();
        }
        else if (choice == 6)
        {
            cout << "EXITING.." << endl;
            return 0;
        }}while (choice != 6);
        return 0;
    }