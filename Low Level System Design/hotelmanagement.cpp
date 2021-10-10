#include <bits/stdc++.h>
using namespace std;



class Hotel{
    string name;
    int id;
    Location hotelLocation;
    vector<Room> roomList;
};
class Location{
 
 int pinCode;
 string street;
 string area;
 string city;
 string country;
 
};
class Room{

    int roomNumber;
    int floorNumber;
    RoomStatus status;
    RoomStyle roomStyle;
    int bookingPrice;
    vector<RoomKey> roomKeys;
    vector<HouseKeepingLog> houseKeepingLogs ; 


};

enum class RoomStatus{
    booked , occupied , available ,ServiceInProgress
};

enum class RoomStyle{
    Standard , Deluxe , Family , Suite
};

class RoomKey{

    string keyId;
    string assignedTo;
    bool isActive;
    bool masterKey; 
    Date issuedAt;

    void assignRoom(Room room){

    }
};

class HouseKeepingLog
{
    string description;
    Date startDate;
    int duration;
    HouseKeeper houseKeeper;

    void addRoom(Room room){

    }
};

class Date{
    int date;
    int month;
    int year;
};

class Person{

    string name;
    Account accountDetail;
    string phone;

};

class Account{
    string username;
    string password;

    AccountStatus accountStatus;
};

enum class  AccountStatus{

    ACTIVE , CLOSED , BLOCKED

};

class HouseKeeper:public Person{

    vector<Room> getRoomServiced(Date date){


    }
};

class Guest:public Person{

    SearchRoom searchRoom;
    BookRoom bookRoom;

};

class Receptionist:public Person{

    SearchRoom searchRoom;
    BookRoom bookRoom;

};

class Admin: public Person{

    void addRoom(Room room)
    {

    }
    Room deleteRoom(string roomId)
    {

    }
    void editRoom(Room room)
    {

    }

};

class SearchRoom{
    vector<Room> searchRoom(RoomStyle r1, Date startDate){

    }
};
class BookRoom{
    
    RoomBooking createBooking(Guest guestInfo)
    {

    }

    RoomBooking cancelBooking(int bookingID)
    {
        
    }
};

class RoomBooking{

    string bookingID;
    Date startDate;
    int durationInDays;
    BookingStatus bookingStatus;
    vector<Guest> guests;
    vector<Room> rooms;
    Charges charges;
};

enum class BookingStatus{


};


// Decorator pattern is used to decorate the prices 

class Charges{

    int baseRoomCharges;
    int 

};


int main()
{
    return 0;
}