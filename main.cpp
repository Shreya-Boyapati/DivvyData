#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

// Station
//
// stores values about stations
//
struct Station {
    string   ID;
    int      Capacity;
    double   Latitude;
    double   Longitude;
    string   Name;
    double   Dist;
    int      Trips;
};

// Bike
//
// stores values about bike trips
//
struct Bike {
    string   Trip;
    string   Bike;
    string   Start;
    string   End;
    int      Duration;
    string   Time;
    int      Hour;
    int      Min;
};

//
// distBetween2Points
//
// Returns the distance in miles between 2 points (lat1, long1) and 
// (lat2, long2).  Latitudes are positive above the equator and 
// negative below; longitudes are positive heading east of Greenwich 
// and negative heading west.  Example: Chicago is (41.88, -87.63).
//
// 
// Originally written by: Prof. Hummel, U. of Illinois, Chicago, Spring 2021
// Reference: http://www8.nau.edu/cvm/latlon_formula.html
//
double distBetween2Points(double lat1, double long1, double lat2, double long2) {
  double PI = 3.14159265;
  double earth_rad = 3963.1;  // statue miles:

  double lat1_rad = lat1 * PI / 180.0;
  double long1_rad = long1 * PI / 180.0;
  double lat2_rad = lat2 * PI / 180.0;
  double long2_rad = long2 * PI / 180.0;

  double dist = earth_rad * acos(
    (cos(lat1_rad) * cos(long1_rad) * cos(lat2_rad) * cos(long2_rad))
    +
    (cos(lat1_rad) * sin(long1_rad) * cos(lat2_rad) * sin(long2_rad))
    +
    (sin(lat1_rad) * sin(lat2_rad))
  );

  return dist;
}

//
// distSort
//
// sorts elements by distance
//
void distSort(Station* A, int N) {
    int minIndex;
    
    for (int i = 0; i < N-1; i++) {
        minIndex = i; 

        for (int j = i + 1; j < N; j++) {
            if (A[j].Dist < A[minIndex].Dist){  
            
                minIndex = j;
            }
        }

        Station temp;

        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

int search(Station* A, int N, string variable){
    for (int i = 0; i < N; ++i){
        if (A[i].Name == variable){
            return i; 
        }
    }
    return -1;
}

//
// alphaSort
//
// sorts elements in alphabetical order
//
void alphaSort(Station* A, int N) {
    int minIndex;
    
    for (int i = 0; i < N-1; i++) {
        minIndex = i; 

        for (int j = i + 1; j < N; j++) {
            if (A[j].Name < A[minIndex].Name){  
            
                minIndex = j;
            }
        }

        Station temp;

        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}

//
// quick_stats
// 
// outputs statistics about stations and trips
//
void quick_stats(Station A[], int N, int X){
    int stations, trips, capacity;
            
    stations = N;
    cout << "  stations: " << stations << endl; 
            
    trips = X;
    cout << "  trips: " << trips << endl;
            
    capacity = 0;
            
    for (int i = 0; i < N; i++){
        capacity = capacity + A[i].Capacity;
    }
    
    cout << "  total bike capacity: " << capacity << endl;
}

//
// durations
//
// outputs summary of bike durations
//
void durations(Bike B[], int X){
    int trips_1 = 0;
    int trips_2 = 0;
    int trips_3 = 0; 
    int trips_4 = 0;
    int trips_5 = 0;
            
    for (int i = 0; i < X; i++){
        if (B[i].Duration <= 1800){
            trips_1++;
        }
        else if (B[i].Duration <= 3600){
            trips_2++;
        }
        else if (B[i].Duration <= 7200){
            trips_3++;
        }
        else if (B[i].Duration <= 18000){
            trips_4++;
        }
        else {
            trips_5++;
        }
    }
            
    cout << "  trips <= 30 mins: " << trips_1 << endl;
    cout << "  trips 30..60 mins: " << trips_2 << endl;
    cout << "  trips 1-2 hrs: " << trips_3 << endl;
    cout << "  trips 2-5 hrs: " << trips_4 << endl;
    cout << "  trips > 5 hrs: " << trips_5 << endl;
}

//
// count_trips
//
// counts trips starting at certain hour
//
void count_trips(Bike B[], int X){
    int hour_0 = 0, hour_1 = 0, hour_2 = 0, hour_3 = 0, hour_4 = 0, hour_5 = 0, hour_6 = 0,
        hour_7 = 0, hour_8 = 0, hour_9 = 0, hour_10 = 0, hour_11 = 0, hour_12 = 0,
        hour_13 = 0, hour_14 = 0, hour_15 = 0, hour_16 = 0, hour_17 = 0, hour_18 = 0,
        hour_19 = 0, hour_20 = 0, hour_21 = 0, hour_22 = 0, hour_23 = 0;
    
    for (int i = 0; i < X; i++){
        if (B[i].Hour == 0){
            hour_0++;
        }
        else if (B[i].Hour == 1){
            hour_1++;
        }
        else if (B[i].Hour == 2){
            hour_2++;
        }
        else if (B[i].Hour == 3){
            hour_3++;
        }
        else if (B[i].Hour == 4){
            hour_4++;
        }
        else if (B[i].Hour == 5){
            hour_5++;
        }
        else if (B[i].Hour == 6){
            hour_6++;
        }
        else if (B[i].Hour == 7){
            hour_7++;
        }
        else if (B[i].Hour == 8){
            hour_8++;
        }
        else if (B[i].Hour == 9){
            hour_9++;
        }
        else if (B[i].Hour == 10){
            hour_10++;
        }
        else if (B[i].Hour == 11){
            hour_11++;
        }
        else if (B[i].Hour == 12){
            hour_12++;
        }
        else if (B[i].Hour == 13){
            hour_13++;
        }
        else if (B[i].Hour == 14){
            hour_14++;
        }
        else if (B[i].Hour == 15){
            hour_15++;
        }
        else if (B[i].Hour == 16){
            hour_16++;
        }
        else if (B[i].Hour == 17){
            hour_17++;
        }
        else if (B[i].Hour == 18){
            hour_18++;
        }
        else if (B[i].Hour == 19){
            hour_19++;
        }
        else if (B[i].Hour == 20){
            hour_20++;
        }
        else if (B[i].Hour == 21){
            hour_21++;
        }
        else if (B[i].Hour == 22){
            hour_22++;
        }
        else if (B[i].Hour == 23){
            hour_23++;
        }
    }
    
    cout << "  0: " << hour_0 << "\n  1: " << hour_1 << "\n  2: " << hour_2 << endl;
    cout << "  3: " << hour_3 << "\n  4: " << hour_4 << "\n  5: " << hour_5 << endl;
    cout << "  6: " << hour_6 << "\n  7: " << hour_7 << "\n  8: " << hour_8 << endl;
    cout << "  9: " << hour_9 << "\n  10: " << hour_10 << "\n  11: " << hour_11 << endl;
    cout << "  12: " << hour_12 << "\n  13: " << hour_13 << "\n  14: " << hour_14 << endl;
    cout << "  15: " << hour_15 << "\n  16: " << hour_16 << "\n  17: " << hour_17 << endl;
    cout << "  18: " << hour_18 << "\n  19: " << hour_19 << "\n  20: " << hour_20 << endl;
    cout << "  21: " << hour_21 << "\n  22: " << hour_22 << "\n  23: " << hour_23 << endl;
}

//
// near_stations
//
// outputs stations within a specified distance
//
void near_stations(Station A[], int N){
    double lat, lon, distance, x;
    cin >> lat;
    cin >> lon;
    cin >> distance;
            
    int y = 0;
            
    cout << "The following stations are within " << distance << " miles of (" << lat << ", " << lon << "):" << endl;
            
    for (int i = 0; i < N; i++){
        x = distBetween2Points(lat, lon, A[i].Latitude, A[i].Longitude);
                
        A[i].Dist = x;
                
        if (x <= distance){
            y++;
        }
    }
            
    if (y == 0){
        cout << "  none found" << endl;
    }
    else{
        Station* near = new Station[y];
                
        int j = 0;
                
        for (int i = 0; i < N; i++){
            if (A[i].Dist <= distance){
                near[j] = A[i];
                j++;
            }
        }
                
        distSort(near, j);
                
        for (int i = 0; i < j; i++){
            cout << "  station " << near[i].ID << " (" << near[i].Name << "): " << near[i].Dist << " miles" << endl;
        }
                
        delete[] near;
    }
}

//
// tripsCount
//
// counts number of trips for each station
//
void tripsCount(Station A[], int N, Bike B[], int X){
    for (int i = 0; i < X; i++){
        for (int j = 0; j < N; j++){
            if (B[i].Start == A[j].ID){
                A[j].Trips++;
            }
                    
            if (B[i].End == A[j].ID && B[i].Start != B[i].End){
                A[j].Trips++;
            }
        }
    }
}

//
// findStations
//
// finds all stations that contain specified keyword
//
void findStations(Station A[], int N, Bike B[], int X){
    string keyw;
    cin >> keyw;
            
    int y = 0;
            
    for (int i = 0; i < N; i++){
        if (A[i].Name.find(keyw) != string::npos){
            y++;
        }
    }
            
    if (y == 0){
        cout << "  none found" << endl;
    }
    else{
        Station* contains = new Station[y];
                
        int j = 0;
                
        for (int i = 0; i < N; i++){
            if (A[i].Name.find(keyw) != string::npos){
                contains[j] = A[i];
                j++;
            }
        }
                
        alphaSort(contains, j);
                
        for (int i = 0; i < j; i++){
            cout << contains[i].Name << " (" << contains[i].ID << ") @ (" << contains[i].Latitude << ", "
            << contains[i].Longitude << "), " << contains[i].Capacity << " capacity, " << contains[i].Trips << " trips" << endl;
        }
        
        delete[] contains;
    }
}

//
// Midnight
//
// executed if trips fall across midnight
//
void Midnight(Station A[], int N, Bike B[], int X, int start, int end){
    int count = 0;
    double total = 0;
    
    for (int i = 0; i < X; i++){
        if(B[i].Min >= start || B[i].Min <= end){
            count++;
            total = total + (B[i].Duration/60.0);
        }
    }
    
    Station* start_stations = new Station[count];
    int k = 0;
    
    for (int i = 0; i < X; i++){
        if(B[i].Min >= start || B[i].Min <= end){
            for (int j = 0; j < N; j++){
                if (B[i].Start == A[j].ID){
                    int x = search(start_stations, count, A[j].Name);
                    
                    if (x == -1){
                        start_stations[k] = A[j];
                        k++;
                    }
                }
            }
        }
    }
    
    int avg;
    
    if (count != 0){
        avg = total / count;
        
        cout << "  " << count << " trips found" << endl;
        cout << "  avg duration: " << avg << " minutes" << endl;
        cout << "  stations where trip started: ";
    
        alphaSort(start_stations, k);
    
        for (int i = 0; i < k-1; i++){
            cout << start_stations[i].Name << ", ";
        }
    
        cout << start_stations[k-1].Name << endl;
    }
    else {
        cout << "   none found" << endl;
    }
    
    delete[] start_stations;
}

//
// notMidnight
// 
// executed if trips do not fall across midnight
//
void notMidnight(Station A[], int N, Bike B[], int X, int start, int end){
    int count = 0;
    double total = 0;
    
    for (int i = 0; i < X; i++){
        if(B[i].Min >= start && B[i].Min <= end){
            count++;
            total = total + (B[i].Duration/60.0);
        }
    }
    
    Station* start_stations = new Station[count];
    int k = 0;
    
    for (int i = 0; i < X; i++){
        if(B[i].Min >= start && B[i].Min <= end){
            for (int j = 0; j < N; j++){
                if (B[i].Start == A[j].ID){
                    int x = search(start_stations, count, A[j].Name);
                    
                    if (x == -1){
                        start_stations[k] = A[j];
                        k++;
                    }
                }
            }
        }
    }
   
    int avg;
    
    if (count != 0){
        avg = total / count;
    
        cout << "  " << count << " trips found" << endl;
        cout << "  avg duration: " << avg << " minutes" << endl;
        cout << "  stations where trip started: ";
    
        alphaSort(start_stations, k);
    
        for (int i = 0; i < k-1; i++){
            cout << start_stations[i].Name << ", ";
        }
    
        cout << start_stations[k-1].Name << endl;
    }
    else {
        cout << "   none found" << endl;
    }
    
    delete[] start_stations;
}


//
// findTrips
//
// finds trips that fall within a given timespan
//
void findTrips(Station A[], int N, Bike B[], int X){
    string start_time, end_time;
    cin >> start_time;
    cin >> end_time;
            
    int sep = start_time.find(":");
    int start_hour = stoi(start_time.substr(0, sep));
    int start_min = stoi(start_time.substr(sep+1, 2));
            
    int sepa = end_time.find(":");
    int end_hour = stoi(end_time.substr(0, sepa));
    int end_min = stoi(end_time.substr(sepa+1, 2));
            
    int start = start_hour*60 + start_min;
    int end = end_hour*60 + end_min;
    
    if (start > end){
        Midnight(A, N, B, X, start, end);
    }
    else {
        notMidnight(A, N, B, X, start, end);
    }  
}

//
// executeStmt
//
// executes program
void executeStmt(Station A[], int N, Bike B[], int X){
    string command;
    cout << "Enter command (# to stop)> ";
    cin >> command;
    
    while (command != "#"){
        if (command == "stats"){
            quick_stats(A, N, X);
        }
        else if (command == "durations"){
            durations(B, X);
        }
        else if (command == "starting"){
            count_trips(B, X);
        }
        else if (command == "nearme"){
            near_stations(A, N);
        }    
        else if (command == "stations"){
            alphaSort(A, N);
            
            for (int i = 0; i < N; i++){
                cout << A[i].Name << " (" << A[i].ID << ") @ (" << A[i].Latitude << ", "
                << A[i].Longitude << "), " << A[i].Capacity << " capacity, " << A[i].Trips << " trips" << endl;
            }
        }
        else if (command == "find"){
            findStations(A, N, B, X);
        }
        else if (command == "trips"){
            findTrips(A, N, B, X);
        }
        else {
            cout << "** Invalid command, try again..." << endl;
        }
        cout << "Enter command (# to stop)> ";
        cin >> command;
    }
    cout << "** Done **\n";
}

int main() {
    //
    // Input filenames, confirm file can be opened, and input data:
    //
    
    cout << "** Divvy Bike Data Analysis **" << endl;
    
    // station file
    string station_filename;
    cout << "Please enter name of stations file> " << endl;
    cin >> station_filename;
    
    ifstream  infile;
    infile.open(station_filename);
    
    if (!infile.good()) {
      cout << "**Error: unable to open input file '" << station_filename << "'" << endl;
      return 0;
    }
    
    int N;
    infile >> N;
    
    Station* A = new Station[N]; // array for stations
    
    string id, name;
    int capacity;
    double latitude, longitude;
    
    for (int i = 0; i < N; ++i){
        infile >> id;
        A[i].ID = id;
        
        infile >> capacity;
        A[i].Capacity = capacity;
        
        infile >> latitude;
        A[i].Latitude = latitude;
        
        infile >> longitude;
        A[i].Longitude = longitude;
        
        getline(infile, name);
        name.erase(0, 1);
        A[i].Name = name;
        
        A[i].Trips = 0;
    }
    
    // bike trips file
    string bike_filename;
    cout << "Please enter name of bike trips file> " << endl;
    cin >> bike_filename;
    
    ifstream  ifile;
    ifile.open(bike_filename);
    
    if (!ifile.good()) {
      cout << "**Error: unable to open input file '" << bike_filename << "'" << endl;
      delete[] A;
      return 0;
    }
    
    int X;
    ifile >> X;
    
    Bike* B = new Bike[X]; // array for bike trips
    
    string trip, bike, start, end, time;
    int duration;
    
    for (int i = 0; i < X; ++i){
        ifile >> trip;
        B[i].Trip = trip;
        
        ifile >> bike;
        B[i].Bike = bike;
        
        ifile >> start;
        B[i].Start = start;
        
        ifile >> end;
        B[i].End = end;
        
        ifile >> duration;
        B[i].Duration = duration;
        
        getline(ifile, time);
        time.erase(0, 1);
        B[i].Time = time;
        
        int sep = time.find(":");
        B[i].Hour = stoi(time.substr(0, sep));
        B[i].Min = B[i].Hour*60 + stoi(time.substr(sep+1, 2));
    }
    
    tripsCount(A, N, B, X);
    
    string c = "aBE";

    c = toupper(c);

    cout << c << endl;
    
    
    executeStmt(A, N, B, X);
    
    delete[] A;
    delete[] B;

    return 0;
}    