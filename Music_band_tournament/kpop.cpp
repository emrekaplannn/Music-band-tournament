#include "kpop.h"
#include "metal.h"
#include "jazz.h"
#include "rock.h"

int KPopBand::play(MusicBand *other)
{
    //std::cout<<"ilk enerji" << this->get_energy()<<endl;
    double score=((this->get_talent())* ( this->get_energy())*0.1) + (this->get_fan_count());
    this->set_energy(this->get_energy()*0.8);

    KPopBand* kpop = dynamic_cast<KPopBand*>(other);
    JazzBand* jazz = dynamic_cast<JazzBand*>(other);
    MetalBand* metal = dynamic_cast<MetalBand*>(other);
    RockBand* rock = dynamic_cast<RockBand*>(other);
    
    if (kpop != nullptr) {
        score *= 2;
    }
    else if(rock != nullptr || metal != nullptr || jazz != nullptr){
        score *= 0.5;
    }

    return score;
}

void KPopBand::rehearse(void) 
{

    this->set_energy(this->get_energy() - ((this->get_energy())*0.2*0.5));
}