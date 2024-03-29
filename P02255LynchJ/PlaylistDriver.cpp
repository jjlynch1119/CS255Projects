// PlaylistDriver.cpp -- MOST FUNCTIONS ARE COMPLETE -- "processMenuChoice" needs to be done
// DO NOT INCLUDE ANYTHING OTHER THAN THESE LIBRARIES/CLASSES
#include <iostream>
#include <limits>
#include "Playlist.h"

using namespace std;

// THE FOLLOWING FUNCTION DECLARATIONS ARE COMPLETE -- DO NOT CHANGE
char getMenuChoice();
void processMenuChoice(char, Playlist&);
int getInteger();
bool isInteger(const string& s);

// THE FOLLOWING FUNCTION IS COMPLETE -- DO NOT CHANGE
int main() {
	Playlist playlist;
	char choice = ' ';

	choice = getMenuChoice();

	while (choice != 'q') {
		processMenuChoice(choice, playlist);
		choice = getMenuChoice();
	}

	cout << "\n>>> Exiting Playlist <<<" << endl;

	return 0;
}

// THE FOLLOWING FUNCTION IS COMPLETE -- DO NOT CHANGE
char getMenuChoice() {
	// Output menu option, prompt users for valid selection
	string menuOptions = "adpstocq";
	char choice = ' ';

	do {
		cout << "\n ************** PLAYLIST MENU **************************" << endl;

		cout << "\ta - Add song" << endl;
		cout << "\td - Remove song" << endl;
		cout << "\tp - Change position of song" << endl;
		cout << "\ts - Output songs by specific artist" << endl;
		cout << "\tt - Output total time of playlist (in seconds)" << endl;
		cout << "\to - Output full playlist" << endl;
		cout << "\tc - Clear playlist" << endl;
		cout << "\tq - Quit" << endl << endl;

		cout << "\tChoose option: ";
		cin >> choice;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << " *******************************************************" << endl;

	} while (menuOptions.find(choice) == string::npos);

	return choice;
}

// ************************** TO BE COMPLETED ******************************************
void processMenuChoice(char choice, Playlist& playlist) {
	// Declaration of local variables needed for this function
	SongNode* songNode = nullptr;
	string uniqueID;
	string songName;
	string artistName;
	int songLength = 0;

	int nodeCount = 0;
	int currPosition = 0;
	int newPosition = 0;

	// COMPLETE THE ACTIONS FOR EACH CHOICE
	// Call corresponding menu action -- don't forget to add "break" statements
	switch (choice) {
	case 'a':
		// Add song to playlist
		// Prompt user for song unique id
		// if the playlist already contains this id
		//		print message and break
		// otherwise
		//		prompt for the rest of the song information
		//		create a new SongNode
		//		insert at the front of the playlist
		//		print the playlist

		cout << "\n\tAdd Song - Enter song's unique ID: ";
		cin >> uniqueID;

		if (playlist.contains(uniqueID)) {
			cout << "\n\t<<< Duplicate unique ID - not added! >>>\n";
			break;
		}

		cout << "\t\tEnter song's name: ";
		cin.ignore();
		getline(cin, songName);
		cout << "\t\tEnter artist's name: ";
		getline(cin, artistName);
		cout << "\t\tEnter song's length (in seconds): ";
		songLength = getInteger();

		songNode = new SongNode(uniqueID, songName, artistName, songLength, nullptr);

		playlist.insertFront(songNode);
		playlist.printPlaylist();

		break;
	case 'd':
		// Remove song from playlist
		// Prompt user for song unique id
		// call remove
		// print appropriate message based on results from remove
		// print the playlist
		cout << "\n\tDelete Song - Enter song's unique ID: ";
		cin >> uniqueID;

		if (playlist.remove(uniqueID) == true) {
			cout << "\n\t<<< Successfully deleted song with unique ID " << uniqueID << " >>>\n";
		} 
		else {
			cout << "\n\t<<< Song with unique ID " << uniqueID << " is not in playlist! >>>\n";
		}
		playlist.printPlaylist();

		break;
	case 'p':
		// Change song position in playlist
		// count the number of songs in the list
		// if the count <=1
		//		print appropriate message
		// otherwise
		//		ask user for valid current position -- use getInteger() to get value
		//			if entry invalid break with appropriate message
		//		ask user for valid new position -- use getInteger() to get value
		//			if entry invalid break with appropriate message
		//
		//		call changeSongPosition
		//		print out message
		//		print playlist
		cout << "\n\tChange Song's Playlist Position - \n";

		nodeCount = playlist.getNodeCount();

		if (nodeCount <= 1) {
			cout << "\n\tThere is one or zero songs in the playlist!\n";
		}
		else {
			cout << "\t\tCurrent position (1 through " << nodeCount << "): ";
			
			currPosition = getInteger();

			if (currPosition > nodeCount || currPosition < 1) {
				cout << "\n\t\t<<< Invalid current position! >>>\n";
				break;
			}

			cout << "\t\tNew position (1 through " << nodeCount << "): ";

			newPosition = getInteger();

			if (newPosition > nodeCount || newPosition == currPosition) {
				cout << "\n\t\t<<< Invalid new position! >>>\n";
				break;
			}

			playlist.changeSongPosition(currPosition, newPosition);

			cout << "\n\t<<< Song moved from position " << currPosition << " to position " << 
				newPosition << " >>>\n";

			playlist.printPlaylist();

		}

		break;
	case 's':
		// prompt the user for the artist's name
		// Output playlist for specific artist
		cout << "\n\tSearch Playlist - Enter artist's name: ";
		getline(cin, artistName);

		playlist.printByArtist(artistName);
		 
		break;
	case 't':
		// Output playlist total time
		cout << "\n\tPlaylist Total Time - " << playlist.getTotalTime() << "\n";

		break;
	case 'o':
		// Print the playlist
		playlist.printPlaylist();

		break;
	case 'c':
		// Clear the playlist
		playlist.clearList();
		nodeCount = playlist.getNodeCount();

		cout << "\n\t>>> Playlist has been cleared! <<<\n";

		break;
	}
}

// THE FOLLOWING FUNCTIONS ARE COMPLETE.
// CAN BE USED TO GET AN INTEGER AND DO THE APPROPRIATE VALIDATION
//		getInteger() uses isInteger()
int getInteger() {
	string str="";
	getline(cin, str);

	while (!(isInteger(str))) {
		cout << "\t\t\t>>> Invalid integer - please enter an integer: ";
		getline(cin, str);
	}

	// convert str to an int
	return stoi(str);
}

bool isInteger(const std::string& s)
{
	if (s.empty() || ((!isdigit(s[0])) && (s[0] != '-') && (s[0] != '+'))) return false;

	char* p; //stores the first location of non-integer character

	// The C library function long int strtol(const char *str, char **endptr, int base)
	//		converts the initial part of the string in str to a long int value according
	//		to the given base, which must be between 2 and 36 inclusive, or be the special value 0.
	strtol(s.c_str(), &p, 10);

	return (*p == 0); // will be true if s contains an integer
}

