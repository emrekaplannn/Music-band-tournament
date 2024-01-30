#include "tournament_round.h"

// TournamentRound functions goes here

TournamentRound::TournamentRound() { }
TournamentRound::TournamentRound(std::list<MusicBand*>_bands) {
    this->bands= _bands;
    
}
TournamentRound::TournamentRound(std::vector<MusicBand*>_bands) { 
    this->bands = std::list<MusicBand*>(_bands.begin(), _bands.end());

}

std::size_t TournamentRound::size() { return (this->bands).size(); }
    

TournamentRound& TournamentRound::operator=(TournamentRound&& other) {
    if(this != &other) {
        bands = std::move(other.bands);
    }
    return *this;
    
}
TournamentRound& TournamentRound::get_next_round() { 
    std::list<MusicBand*> winners;
    while (bands.size() > 1) {

        MusicBand* winner;

        
        MusicBand* band1 = bands.front();
        MusicBand* band2 = bands.back();
        bands.erase(bands.begin());
        bands.pop_back();
        
        int score1 = band1->play(band2);
        int score2 = band2->play(band1);
        
        int fan_change = 0;
        if(score1>= score2){
            fan_change = score1-score2;
        }
        else{
            fan_change = score2-score1;
        }
       
        if (score1 >= score2) {
            int fan_winner = band1->get_fan_count() + std::min(fan_change, band2->get_fan_count());
            band1->set_fan_count(fan_winner);
            int fan_loser;
            if((band2->get_fan_count() - fan_change) < 0){
                fan_loser = 0;
            }
            else{
                fan_loser = band2->get_fan_count() - fan_change;
            }
            band2->set_fan_count(fan_loser);
            winner = band1;
        }
        else {
            int fan_winner = band2->get_fan_count() + std::min(fan_change, band1->get_fan_count());
            band2->set_fan_count(fan_winner);
            int fan_loser;
            if((band1->get_fan_count() - fan_change) < 0){
                fan_loser = 0;
            }
            else{
                fan_loser = band1->get_fan_count() - fan_change;
            }
            band1->set_fan_count(fan_loser);
            winner = band2;
        }
        winners.push_back(winner);
    }
    
    // middle team adding
    if(bands.size() ==1 ){
        int middle = (int) bands.size() -1;
        std::list<MusicBand*>::iterator it = bands.begin(); 
        for(int i = 0 ; i<middle ; i++){
               ++it;
        }
            winners.push_back(*it);
    }
    
    bands = winners;
    return *this;
    
}

std::ostream& operator<< (std::ostream &os, TournamentRound &other) { 
    for(std::list<MusicBand*>::iterator it = other.bands.begin(); it != other.bands.end(); ++it) {
        MusicBand* band = *it;
        os << band->get_name();
        if(std::next(it) != other.bands.end()) {
            os << '\t';
        }
    }
    return os; }