#pragma once

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include "item.h"
#include "MembersHash.h"
#include "ItemsHash.h"
#include "user.h"
using namespace std;

class Item;
//void commandFile(HashTableItems<long long int>& items,HashTable<long long int>& members);
int nextPrimeI( int n );

// QuadraticProbing Hash table class
//
// CONSTRUCTION: an approximate initial size or default of 101
//
// ******************PUBLIC OPERATIONS*********************
// bool insert( x )       --> Insert x
// bool remove( x )       --> Remove x
// bool contains( x )     --> Return true if x is present
// void makeEmpty( )      --> Remove all items
// int hashCode( string str ) --> Global method to hash strings

template <typename HashedObj>
class HashTableItems
{
  public:
    explicit HashTableItems( int size = 101 ) : array( nextPrimeI( size ) ), objects(nextPrimeI(size))
      { makeEmpty( ); }

    bool contains( const HashedObj & x ) const
    {
        return isActive( findPos( x ) );
    }

    void makeEmpty( )
    {
        currentSize = 0;
        for( auto & entry : array )
            entry.info = EMPTY;
    }

    bool insert( const HashedObj & x ,Item& item)
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;

        if( array[ currentPos ].info != DELETED )
            ++currentSize;

        array[ currentPos ].element = x;
        objects[ currentPos ] = item;
        array[ currentPos ].info = ACTIVE;

            // Rehash; see Section 5.5
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }
    
    bool insert( HashedObj && x,Item& item)
    {
            // Insert x as active
        int currentPos = findPos( x );
        if( isActive( currentPos ) )
            return false;
        if( array[ currentPos ].info != DELETED )
            ++currentSize;
        array[ currentPos ] = std::move( x );
        objects[ currentPos ] = item;
        array[ currentPos ].info = ACTIVE;
            // Rehash; see Section 5.5
        if( currentSize > array.size( ) / 2 )
            rehash( );

        return true;
    }

    bool remove( const HashedObj & x )
    {
        int currentPos = findPos( x );
        if( !isActive( currentPos ) )
            return false;

        array[ currentPos ].info = DELETED;
        return true;
    }
    int findPos( const HashedObj & x ) const
    {
        int offset = 1;
        int currentPos = myhash( x );

        while( array[ currentPos ].info != EMPTY &&
               array[ currentPos ].element != x )
        {
            currentPos += offset;  // Compute ith probe
            offset += 2;
            if( currentPos >= array.size( ) )
                currentPos -= array.size( );
        }

        return currentPos;
    }

    enum EntryType { ACTIVE, EMPTY, DELETED };

    vector<Item> objects;
  private:
    struct HashEntry
    {
        HashedObj element;
        EntryType info;

        HashEntry( const HashedObj & e = HashedObj{ }, EntryType i = EMPTY )
          : element{ e }, info{ i } { }
        
        HashEntry( HashedObj && e, EntryType i = EMPTY )
          : element{ std::move( e ) }, info{ i } { }
    };
    
    vector<HashEntry> array;
    int currentSize;

    bool isActive( int currentPos ) const
      { return array[ currentPos ].info == ACTIVE; }


    void rehash( )
    {
        vector<HashEntry> oldArray = array;
        vector<Item> old = objects;

            // Create new double-sized, empty table
        array.resize( nextPrimeI( 2 * oldArray.size( ) ) );
        objects.resize( nextPrimeI( 2 * oldArray.size( ) ));
        for( auto & entry : array )
            entry.info = EMPTY;

            // Copy table over
        int counter = 0;
        currentSize = 0;
        for( auto & entry : oldArray )
        {
            if( entry.info == ACTIVE )
            {
                insert( std::move( entry.element ) , old[counter]);
            }
            counter++;
        }
    }

    size_t myhash( const HashedObj & x ) const
    {
        static hash<HashedObj> hf;
        return hf( x ) % array.size( );
    }

    friend class User;
    friend void commandFile(HashTableItems<long long int>&,HashTable<long long int>&);
};

