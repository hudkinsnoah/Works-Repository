//----------------------------------------------------------
// CS260 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may not be republished without approval.
//----------------------------------------------------------

#include "IndexMap.h"
#include <vector>

using namespace std;


IndexMap::IndexMap(int startingBuckets){
    numBuckets = startingBuckets;
    keyCount = 0;
    buckets = new IndexRecord[numBuckets];
}


IndexMap& IndexMap::operator=(const IndexMap& other){

    this->keyCount = other.numKeys();
    this->numBuckets = other.numBuckets;
    this->buckets = new IndexRecord[numBuckets];

    for(int i = 0; i < numBuckets; i++)
        this->buckets[i] = other.buckets[i];

    return *this;
}


unsigned int IndexMap::getLocationFor(const std::string& key) const{
    std::hash<string> hasher;

    unsigned int hashValue = static_cast<unsigned int>(hasher(key));

    return hashValue % numBuckets;
}


bool IndexMap::contains(const std::string& key) const{
    if(key == "?" || key == "#")
            throw invalid_argument("Invalid key");

        int bucketNumber = getLocationFor(key);



        while(buckets[bucketNumber].word != "?" || buckets[bucketNumber].word != "#")
        {
            if(buckets[bucketNumber].word == key)
                return true;
            else if(buckets[bucketNumber].word == "?")
                return false;
            else
            {
                if(bucketNumber == numBuckets - 1)
                    bucketNumber = 0;
                else
                    bucketNumber++;
            }

        }

        return false;
    }


int IndexMap::numKeys() const{
    return keyCount;
}


int IndexMap::find(const std::string& word){
    if(word == "?" || word == "#")
        throw invalid_argument("invalid Key");

    if(!contains(word))
    {
        return -1;
    }
    else
    {
        int temp = getLocationFor(word);

        while(buckets[temp].word != "")
        {
            if(buckets[temp].word == word)
                return temp;
            else if(temp == numBuckets - 1)
                    temp = 0;
            else
                    temp++;
        }
        return temp;
    }

}


void IndexMap::add(const std::string& key, int pageNumber, int wordNumber){
    if(key == "?" || key == "#")
        throw invalid_argument("invalid Key");

    if(numKeys() >= numBuckets)
        grow();

    int bucketNumber = getLocationFor(key);

        if(contains(key)){
            bucketNumber = find(key);
            if(bucketNumber == -1)
                throw invalid_argument("invalid bucketNumber");
            else
                buckets[bucketNumber].addLocation(IndexLocation(pageNumber, wordNumber));
        }
        else{
            while(buckets[bucketNumber].word != "?" && buckets[bucketNumber].word != "#")
                {
                    if(bucketNumber == numBuckets - 1)
                            bucketNumber = 0;
                        else
                            bucketNumber++;
                }

            buckets[bucketNumber].addLocation(IndexLocation(pageNumber, wordNumber));
            buckets[bucketNumber].word = key;
            this->keyCount++;
        }

}


IndexMap::~IndexMap(){
    delete [] buckets;
}


void IndexMap::grow(){
        IndexRecord* temp = buckets;
        int tempNumbuckets = numBuckets;
        numBuckets = numBuckets * 2 + 1;

        buckets = new IndexRecord[numBuckets];
        this->keyCount = 0;

        for(int i = 0; i < tempNumbuckets; i++){

        if(temp[i].word != "?" && temp[i].word != "#"){
            IndexRecord newRecord = temp[i];
                for(auto it = temp[i].locations.begin(); it < temp[i].locations.end(); it++)
                {
                    this->add(newRecord.word, it->pageNum, it->wordNum);
                }
            }
        }

        delete [] temp;
    }


void IndexMap::print() const{
    for(int i = 0; i < numBuckets; i++)
    {
        if(buckets[i].word != "?")
            cout << buckets[i] << endl;

    }
}


IndexRecord IndexMap::get(const std::string& word) const{

    int temp = getLocationFor(word);

    while(buckets[temp].word != word)
    {
        if(temp == numBuckets - 1)
                temp = 0;
            else
                temp++;
    }



    return buckets[temp];
}


void IndexMap::findWordPairs(const std::string& key1, const std::string& key2) const{

    IndexRecord key1Locations = get(key1);
    IndexRecord key2Locations = get(key2);

        for(auto one = key1Locations.locations.begin(); one < key1Locations.locations.end(); one++)
        {
            for(auto two = key2Locations.locations.begin(); two < key2Locations.locations.end(); two++)
            {
                if(one->pageNum == two->pageNum && one->wordNum == two->wordNum - 1)
                {
                    cout << one->pageNum << "-" << one->wordNum << " " << two->pageNum << "-" << two->wordNum << "  ";
                    break;
                }
            }
        }
         cout << " Are all locations for the pair " << key1 << " and " << key2 << endl;

}


std::string IndexMap::firstWordOnPage(int pageNumber) const{

    for(int i = 0; i < numBuckets; i++)
    {
        if(buckets[i].word != "?"){
            IndexRecord locs = get(buckets[i].word);
            for(auto curlocation = locs.locations.begin(); curlocation < locs.locations.end(); curlocation++){
                if(curlocation->pageNum == pageNumber && curlocation->wordNum == 1){
                    return buckets[i].word;
                }
            }
        }
    }

    return "Invalid Page Number";
}
