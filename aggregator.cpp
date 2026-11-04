#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Artist {
        string name;
        public:
        Artist(string name) : name(name) {}
        string getName() const {
            return name;
        }        
};
// class Playlist;

class Song {
    string title;
    Artist* artist;
    int duration; // in seconds
    public:
    Song( const string &title, Artist* artist, int duration) : title(title), artist(artist), duration(duration) {}
    string getTitle() const {
        return title;
    }
    string getArtistName() const {
        return artist->getName();
    }
    int getDuration() const {
        return duration;
    }
    string toString() const {
        return title + " by " + artist->getName() + " (" + to_string(duration) + "s)";
    }

};

class Playlist {
    string name;
    vector<Song*> songs;
    public:
    Playlist(string name) : name(name) {}
    string getName() const {
        return name;
    }
    void addSong(Song* song) {
        songs.push_back(song);
    }
    void removeSong(Song* song) {
        songs.erase(remove(songs.begin(), songs.end(), song), songs.end());
    }
    int getSongCount() const {
        return songs.size();
    }
    vector<Song*> getSongs() const {
        return songs;
    }
    int getTotalDuration() const {
        int total = 0;
        for (auto* song : songs) {
            total += song->getDuration();
        }
        return total;
    }
};
class User{
    string name;
    vector<Playlist*>playlists;
    public:
    User(string name) : name(name) {}
    Playlist* createPlaylist(string name) {
        Playlist* newPlaylist = new Playlist(name);
        playlists.push_back(newPlaylist);
        return newPlaylist;
    }
    void deletePlaylist(Playlist* playlist) {
        playlists.erase(remove(playlists.begin(), playlists.end(), playlist), playlists.end());
        delete playlist;
    }

};

class Library {
    vector<Song*> songs;
    public:
    void addSong(Song* song) {
        songs.push_back(song);
    }
    int getSongCount() const {
        return songs.size();
    }

};

int main() {
    Artist coldplay("Coldplay");
    Artist adele("Adele");

    Song yellow("Yellow", &coldplay, 269);
    Song clocks("Clocks", &coldplay, 307);
    Song hello("Hello", &adele, 295);
    Song someone("Someone Like You", &adele, 285);

    Library library;
    library.addSong(&yellow);
    library.addSong(&clocks);
    library.addSong(&hello);
    library.addSong(&someone);

    User alice("Alice");
    Playlist* workout = alice.createPlaylist("Workout Mix");
    Playlist* chill = alice.createPlaylist("Chill Vibes");

    workout->addSong(&yellow);
    workout->addSong(&clocks);
    workout->addSong(&hello);

    chill->addSong(&hello);
    chill->addSong(&someone);

    cout << "Library has " << library.getSongCount() << " songs" << endl;
    cout << endl;

    cout << workout->getName() << " (" << workout->getSongCount() << " songs, "
         << workout->getTotalDuration() << "s):" << endl;
    for (auto* s : workout->getSongs())
        cout << "  - " << s->toString() << endl;
    cout << endl;

    cout << chill->getName() << " (" << chill->getSongCount() << " songs, "
         << chill->getTotalDuration() << "s):" << endl;
    for (auto* s : chill->getSongs())
        cout << "  - " << s->toString() << endl;
    cout << endl;

    string workoutName = workout->getName();
    alice.deletePlaylist(workout);
    cout << "After deleting '" << workoutName << "':" << endl;
    cout << "  Library still has " << library.getSongCount() << " songs" << endl;
    cout << "  '" << chill->getName() << "' still has " << chill->getSongCount() << " songs" << endl;
    cout << "  'Yellow' still exists: " << yellow.getTitle() << endl;

    return 0;
}