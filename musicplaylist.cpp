#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node class representing a song
class Node
{
public:
    string title;
    string artist;

    Node* prev;
    Node* next;

    Node(string t, string a)
    {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

// Doubly Linked List for Music Playlist
class MusicPlaylist
{
private:
    Node* head;       // Points to the first song
    Node* current;    // Points to the currently selected song

public:
    MusicPlaylist()
    {
        head = nullptr;
        current = nullptr;

        // Adding the two initial songs
        addSong("Har Funn Maula",
                "Vishal Dadlani and Zara Khan");

        addSong("Teri Jhuki Nazar",
                "Shafqat Amanat Ali");
    }

    // Add a new song at the end
    void addSong(string title, string artist)
    {
        Node* p = new Node(title, artist);

        if (head == nullptr)
        {
            head = p;
            current = p;
        }
        else
        {
            Node* q = head;

            // Traverse to the last node
            while (q->next != nullptr)
            {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    // Delete a song by title
    void deleteSong(string title)
    {
        Node* q = head;

        // Find the song
        while (q != nullptr && q->title != title)
        {
            q = q->next;
        }

        if (q == nullptr)
        {
            cout << "Song not found!\n";
            return;
        }

        Node* p = q;

        // Update current if the current song is deleted
        if (current == p)
        {
            if (p->next != nullptr)
                current = p->next;
            else
                current = p->prev;
        }

        // Delete the first song
        if (p == head)
        {
            head = p->next;

            if (head != nullptr)
                head->prev = nullptr;
        }
        else
        {
            p->prev->next = p->next;

            if (p->next != nullptr)
                p->next->prev = p->prev;
        }

        delete p;

        cout << "Song deleted successfully!\n";
    }

    // Display playlist in forward direction
    void displayPlaylist()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\n--- Music Playlist ---\n";

        while (q != nullptr)
        {
            cout << "Song: " << q->title
                 << " | Artist: " << q->artist;

            if (q == current)
                cout << " <-- CURRENT SONG";

            cout << endl;

            q = q->next;
        }
    }

    // Display playlist in reverse direction
    void displayReverse()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        // Move to the last node
        while (q->next != nullptr)
        {
            q = q->next;
        }

        cout << "\n--- Reverse Playlist ---\n";

        while (q != nullptr)
        {
            cout << q->title << " - "
                 << q->artist << endl;

            q = q->prev;
        }
    }

    // Play the current song
    void playCurrent()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\nNow Playing: " << current->title
             << "\nArtist: " << current->artist << endl;
    }

    // Move to the next song
    void playNext()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->next == nullptr)
        {
            cout << "This is the last song!\n";
            return;
        }

        current = current->next;
        playCurrent();
    }

    // Move to the previous song
    void playPrevious()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->prev == nullptr)
        {
            cout << "This is the first song!\n";
            return;
        }

        current = current->prev;
        playCurrent();
    }

    // Play the complete playlist
    void playCompletePlaylist()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\n--- Playing Complete Playlist ---\n";

        while (q != nullptr)
        {
            cout << "Playing: " << q->title
                 << " | Artist: " << q->artist << endl;

            q = q->next;
        }
    }

    // Repeat the complete playlist
    void repeatAll()
    {
        int repetitions;

        cout << "Enter number of repetitions: ";
        cin >> repetitions;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input!\n";
            return;
        }

        if (repetitions <= 0)
        {
            cout << "Enter a positive number!\n";
            return;
        }

        if (head == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++)
        {
            Node* q = head;

            cout << "\nRepetition " << i << ":\n";

            while (q != nullptr)
            {
                cout << "Playing: " << q->title << endl;
                q = q->next;
            }
        }
    }

    // Show the current song
    void showCurrentSong()
    {
        if (current == nullptr)
        {
            cout << "No song selected!\n";
        }
        else
        {
            cout << "Current Song: " << current->title
                 << "\nArtist: " << current->artist << endl;
        }
    }

    // Destructor to release allocated memory
    ~MusicPlaylist()
    {
        Node* q = head;

        while (q != nullptr)
        {
            Node* p = q;
            q = q->next;
            delete p;
        }

        head = nullptr;
        current = nullptr;
    }
};

// Main function
int main()
{
    MusicPlaylist playlist;
    int choice;

    string title, artist;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            getline(cin, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter song title to delete: ";
            getline(cin, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayPlaylist();
            break;

        case 4:
            playlist.displayReverse();
            break;

        case 5:
            playlist.playCurrent();
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.playCompletePlaylist();
            break;

        case 9:
            playlist.repeatAll();
            break;

        case 10:
            playlist.showCurrentSong();
            break;

        case 11:
            cout << "Exiting Music Playlist Manager...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 11);

    return 0;
}
//output
//PS C:\Users\poona\OneDrive\Documents\Rahul> g++ musicplaylist.cpp -o musicplaylist.exe
//PS C:\Users\poona\OneDrive\Documents\Rahul> ./musicplaylist.exe
//Song added successfully!
//Song added successfully!

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Exit
//Enter your choice: 1
//Enter song title: saiyaara
//Enter artist name: faheem abdullah
//Song added successfully!

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Exit
//Enter your choice: 2
//Enter song title to delete: saiyaara
//Song deleted successfully!

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Exit