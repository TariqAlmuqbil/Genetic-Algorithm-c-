#ifndef __GAMODULE_H__
#define __GAMODULE_H__


#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

using std::vector;

template<class T>
class GAmodule
{
private:
	vector<T> _Creatures;
	vector<unsigned long> _scorOfCreatures;
	T bestCreature;
	std::vector<std::pair<T,unsigned long>> _scoredCreatures;
	int _numberOfGenrations;
	int _numberOfPupulation;
	int _currentGenration=0;
	int _mutationRate;

    void _genrateRandomCreatres();
    void _calclateCreaturesFitness();
    void _cossOverTheCreatures();
    void _mutateTheCreatures();
    void _resetScoresOfCreatures();
    void _printCreaturesData();
    T _mixCreatures(T parent1, T parent2);
public:
    GAmodule(int _numberOfGenrations,
    		int _numberOfPupulation ,
    		int _mutationRate):
    	_numberOfGenrations(_numberOfGenrations),
		_numberOfPupulation(_numberOfPupulation),
		_mutationRate(_mutationRate){};

    ~GAmodule();
    void startEvalotion();
    T getBestResult(){return bestCreature;};
};



template<class T>
GAmodule<T>::~GAmodule()
{
}


template<class T>
void GAmodule<T>::_genrateRandomCreatres()
{
	 for (int i=0;i<_numberOfPupulation;i++){
		_Creatures.push_back(T());
	}
}

template<class T>
void GAmodule<T>::_calclateCreaturesFitness()
{
	for(auto creature : _Creatures){
		_scoredCreatures.push_back(std::make_pair(creature, creature.calculateScore()));
	}

	std::sort(std::begin(_scoredCreatures), std::end(_scoredCreatures),
		[&](const auto& a, const auto& b)
		{
			return a.second > b.second;
		});

	for(int i=0; i<_numberOfPupulation; i++){
		_Creatures[i] = _scoredCreatures[i].first;
	}
}

template<class T>
void GAmodule<T>::_cossOverTheCreatures()
{
	for(int i=0; i<_numberOfPupulation/2; i++){
		if (i%2==0){
			_Creatures[_numberOfPupulation-1-i] = _mixCreatures(_Creatures[i],_Creatures[i+1]);
		}else{
			_Creatures[_numberOfPupulation-1-i] = _mixCreatures(_Creatures[i-1],_Creatures[i]);
		}
	}
}

template<class T>
void GAmodule<T>::_mutateTheCreatures()
{

	const int numberOfparamters = _Creatures[0].paramters.size();
	for(int i=0; i<_numberOfPupulation; i++){
		for (int j =0; j<numberOfparamters; j++){
			if (rand()%100 < _mutationRate){
				_Creatures[i].mutate(j);
			}
		}
	}
}

template<class T>
void GAmodule<T>::startEvalotion()
{
	_genrateRandomCreatres();
	unsigned long maximumScore =0;
	for (int i =0; i<_numberOfGenrations;i++){
		_calclateCreaturesFitness();
		if (this->_Creatures[0].calculateScore() >maximumScore){
			maximumScore =this->_Creatures[0].calculateScore() ;
			bestCreature = _Creatures[0];
		}
		_currentGenration++;
//		_printCreaturesData();
		std::cout << "=============== Generation : " <<_currentGenration << "\n";
		_cossOverTheCreatures();
		_Creatures[0].printThis();
		_mutateTheCreatures();
		_resetScoresOfCreatures();
	}


}

template<class T>
T GAmodule<T>::_mixCreatures(T parent1, T parent2){
	const int numberOfparamters = _Creatures[0].paramters.size();
	T child;
		for (int j =0; j<numberOfparamters; j++){
			if (rand()%2==0){
			child.paramters[j] = parent1.paramters[j];
			} else{
				child.paramters[j] = parent2.paramters[j];
			}
		}
	return child;
}

template<class T>
void GAmodule<T>::_printCreaturesData(){
	std::cout << "=============== Generation : " <<_currentGenration << "\n";
	for(int i=0; i<_numberOfPupulation; i++)
   {
		_Creatures[i].printThis();
   }
}

template<class T>
void GAmodule<T>::_resetScoresOfCreatures(){
	 _scoredCreatures.clear();
}

#endif // __GAMODULE_H__
