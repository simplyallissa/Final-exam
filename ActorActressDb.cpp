//
// Created by Allissa Hertz on 12/3/22.
//

#include "main.h"

vector<ActorActress> loadFromFileActorActressData() {
    int year = 0;
    string award;
    bool winner = true;
    string answer;
    string name;
    string film;

    fstream actor_actress_file;
    //Open the actor_actress_file
    //TODO: Need to not hardcode this file path
    actor_actress_file.open("/Users/allissahertz/CLionProjects/final-project/actor_actress.csv");
    vector<ActorActress> new_actor_actress_vector;
    if(!actor_actress_file){
        cerr<<"File not found\n";
        exit(EXIT_FAILURE);
    } else{
        string line;
        int i = 0;
        while (getline(actor_actress_file, line, '\n')){

            if (i > 0){ //skipping the first line, because it contains the column names.
                //splitString utility function is defined in main.cpp
                vector<string> temp_actor_actress_record = splitString(line, ',');
                ActorActress actorActress(year, award, winner, name, film);
                //for values that are integers, you have to check if the line is empty, because it will fail.
                //-1 appears instead of the empty string, but this is change on print
                if (temp_actor_actress_record[0] == ""){
                    actorActress.setYear(-1);
                }
                else {
                    //assign the year to the first token that was split from the string
                    //stoi converst the string into an integer since it is pulled out of the file as a string, but needs to be converted to an integer type
                    actorActress.setYear(stoi(temp_actor_actress_record[0]));
                }
                actorActress.setAward(temp_actor_actress_record[1]);
                if(temp_actor_actress_record[2] == "")
                {
                    actorActress.setWinner(-1);
                }
                else {
                    actorActress.setWinner(stoi(temp_actor_actress_record[2]));
                }
                actorActress.setName(temp_actor_actress_record[3]);
                actorActress.setFilm(temp_actor_actress_record[4]);
                //Add all of the objects to a vector
                new_actor_actress_vector.push_back(actorActress);
//                cout << actorActress.print() << endl;
            }
            i++;
        }
    }
    //The created vector is passed over to main to be used globally
    return new_actor_actress_vector;
}

void addActorActressRecord() {

    int input_year = 0;
    string input_award;
    string input_winner;
    string input_answer;
    string input_name;
    string input_film;
    bool winner;

    cout << "What year was the award won? Enter a four-digit integer. For example, “1976”.\n";
    cin >> input_year;
    cout << "What was the name of the award?\n";
    cin >> input_award;
    cout << "Did the actor/actress win the award? Enter yes or no.\n";
    cin >> input_winner;
    if (input_winner == "yes"){
        winner = true;
    } else if (input_winner == "no"){
        winner = false;
    } else {
        cout << "You must type in yes or no.";
        addActorActressRecord();
    }
    cout << "What was the name of the actor/actress?\n";
    cin >> input_name;
    cout << "What was the name of the film the actor/actress starred in?\n";
    cin >> input_film;
    ActorActress actorActress(input_year, input_award, winner, input_name, input_film);
    actorActress.setYear(input_year);
    actorActress.setAward(input_award);
    actorActress.setWinner(winner);
    actorActress.setName(input_name);
    actorActress.setFilm(input_film);

    actor_actress_db.push_back(actorActress);
//    cout << "Added entry to database: \n" << actorActress.print() << endl;
}

void printActorActressDb() {
    for (int i = 0; i < actor_actress_db.size(); i++){
//        cout << actor_actress_db[i].print() << endl;
    }
}

void sortActorActress(){
    int fieldName;
    cout << "What field would you like to sort by?/n/n1. Year/n2. Award/n3. Winner/n4.Name/n5.Film";
    //TODO: Add in logic to actually sort the data

}

void searchActorActress(){
    cout << "What would you like to search for?";

}

void saveCSVActorActress() {
    string user_file_name;
    cout << "What would you like to name your file?";
    cin >> user_file_name;
    ofstream outfile(user_file_name);


    //outfile << printActorActressDb() << std::endl;

    outfile.close();


}