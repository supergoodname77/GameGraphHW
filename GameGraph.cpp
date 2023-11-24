
#include "GameGraph.h"
#include <stdlib.h>
#include <string.>
#include <iostream>
#include <fstream>

using namespace std;

GameGraph::GameGraph()
{
    m_iLocation = 0;

    int i;
    int j;

    for(j=0; j<20; j++)
    {
        for(i=0; i<20; i++)
        {
            m_cAdjMatrix[j][i] = '\0';
        }
    }
    
    for(i=0; i<20; i++)
    {
        m_Rms[i].m_sRoomName[64] = {'n'};
        m_Rms[i].m_sRoomDesc[128] = {'n'};
        m_Rms[i].m_sItemName[32] = {'n'};
        m_Rms[i].m_sCreatureName[64] = {'n'};
    }
    
}


GameGraph::~GameGraph()
{
    
}


bool GameGraph::doCommand(char *cmd)
{
    return false;
}

void GameGraph::PrintAll()
{
    int i;
    for(i=0; i<20; i++)
    {
        describeRoom(i);
    }
}

void GameGraph::setLink(int roomIdx, int linkIdx, char dCode)
{
    m_cAdjMatrix[roomIdx][linkIdx] = dCode;
}
void GameGraph::describeRoom(int roomIdx)
{
    cout << m_Rms[roomIdx].m_sRoomName << endl;
    cout << m_Rms[roomIdx].m_sRoomDesc << endl;
    cout << m_Rms[roomIdx].m_sItemName << endl;
    cout << m_Rms[roomIdx].m_sCreatureName << endl;    
    if(FindDoor('N') == true)
    {
        cout << "There is a door in the North wall." << endl;
    }
    if(FindDoor('S') == true)
    {
        cout << "There is a door in the South wall." << endl;
    }
    if(FindDoor('E') == true)
    {
        cout << "There is a door in the East wall." << endl;
    }
    if(FindDoor('W') == true)
    {
        cout << "There is a door in the West wall." << endl;
    }
    if(FindDoor('U') == true)
    {
        cout << "There is a stairway leading up." << endl;
    }
    if(FindDoor('D') == true)
    {
        cout << "There is a stairway leading down." << endl;
    }
    cout << endl;
}
bool GameGraph::FindDoor(char cardinal)
{
    int i;
    char caseref;
    for(i = 0; i<20; i++)
    {
        caseref = m_cAdjMatrix[m_iLocation][i];
        switch(caseref)
        {
            case 'N':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;

            case 'S':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;
            case 'E':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;
            case 'W':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;
            case 'U':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;
            case 'D':
                if(caseref == cardinal)
                {
                    return true;
                }
                break;
            case '\0':
                break;
        }
    }
}

//---------------------------------------
// LoadGame()
// Open and read the game layout file and
//   build the adjacency matrix.
//---------------------------------------
bool GameGraph::LoadGame(char *filename)
{
    char line[128];
    int link;
    bool done;
    //char *tempRoomline;


    m_InFile.open(filename, ifstream::in); 
    if(!m_InFile.is_open())
    {
        // m_InFile.is_open() returns false if the file could not be found or
        //    if for some other reason the open failed.
        cout << "The File is Not being Opened" << endl;
        return false;
    }

    done = false;
    for(int i=0; i<20; i++)
    {
        cout << "The File is successfully being read" << endl;
        // Read room name
        getNextLine(line, 128);
        m_Rms[i].m_sRoomName[64] = *line;
        /* --- Copy room name into data structure i --- */

        // Read room description
        getNextLine(line, 128);
        m_Rms[i].m_sRoomDesc[128] = *line;
        /* --- Copy room description into data structure i --- */

        // Read room item
        getNextLine(line, 128);
        m_Rms[i].m_sItemName[32] = *line;
        /* --- Copy room item name into data structure i --- */

        // Read room creature
        getNextLine(line, 128);
        m_Rms[i].m_sCreatureName[64] = *line;
        /* --- Copy room creature name into data structure i --- */

        // Read North door
        getNextLine(line, 128);
        link = atoi(line); // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'N');
        }
        // Call function to set link in adjacency matrix

        // Read South door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'S');
        }        
        // Call function to set link in adjacency matrix

        // Read East door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'E');
        }        
        // Call function to set link in adjacency matrix

        // Read West door
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'W');
        }        
        // Call function to set link in adjacency matrix

        // Read up stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'U');
        }
        // Call function to set link in adjacency matrix

        // Read down stairway
        getNextLine(line, 128);
        link = atoi(line);    // Convert to room index
        if(link != -1)
        {
            setLink(i,link,'D');
        }        
        // Call function to set link in adjacency matrix
    }
    return true;
}

//-------------------------------------------
// GetNextLine()
// Read the next line from the file.
//-------------------------------------------
void GameGraph::getNextLine(char *line, int lineLen)
{
    int    done = false;

    while(!done)
    {
        m_InFile.getline(line, lineLen);  
        // Note: m_InFile is an ifstream object that is part of the GameGraph class

        if(m_InFile.good())    // If a line was successfully read
        {
           if(strlen(line) == 0)  // Skip any blank lines
                continue;
            else if(line[0] == '#')  // Skip any comment lines
                continue;
            else done = true;    // Got a valid data line so return with this line
        }
        else
        {
            strcpy(line, "");
            return;
        }
    } // end while
}
