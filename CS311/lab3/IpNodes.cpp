#include"IpNodes.hpp"

void IpNodes::setIP(string s)
{
    ipAddress = s;
}

void IpNodes::setNext(IpNodes* h)
{
    next = h;
}

string IpNodes::getIP()
{
    return ipAddress;
}

IpNodes* IpNodes::getNext()
{
    return next;
}

void IpNodes::updateCount()
{
    occurs++;
}

int IpNodes::getCount()
{
    return occurs;
}

void mainMenu(IpNodes**h)
{
    string userBuffer;
    bool quitter = false;

    while(!quitter)
    {
        cout << "\nPlease enter an IP address (or 'Q' to quit): ";
        getline(cin,userBuffer);
        if(userBuffer =="q" || userBuffer == "Q")
        {
            quitter = true;
            continue;
        }
    searchNode(3,h,userBuffer);
    }
    cout << "\nExiting..." << endl;
}

void addNode(IpNodes** h, string address)
{
    IpNodes* newIP = new IpNodes();
    newIP->setIP(address);
    newIP->setNext(*h);
    *h = newIP;
}

void searchNode(int mode,IpNodes** h, string address)
{
    //Modes: (1) - Add/Tally mode | (2) - Dump mode | (3) Query Mode
    switch(mode)
    {
        case 1:
        {
            IpNodes* curr = *h;
            string currentIP;
            static bool firstGo = true;

            if(firstGo)
            {
                addNode(h, address);
                firstGo = false;
                return;
            }
            while(curr != nullptr)
            {
                currentIP = curr->getIP();
                if(currentIP == address)
                {
                    curr->updateCount();
                    return;
                }
                curr = curr->getNext();
            }
            addNode(h,address);
            return;
        }
        case 2:
        {
            IpNodes* curr = *h;
            ofstream dumpDat;
            dumpDat.open("RHIPS-log.dat");
            cout << "\nGenerating dump file...\n" << endl;
            while(curr != nullptr)
            {
                dumpDat << "Address:\t" << curr->getIP() << "\tOccurred:\t"
                     << curr->getCount() << " times." << endl;
                curr = curr->getNext();
            }
            dumpDat.close();
            return;
        }
        case 3:
        {
            IpNodes* curr = *h;
            cout << "\nAttempting to search for: " << address << endl;
            while(curr != nullptr)
            {
                if(curr->getIP() == address)
                {
                    cout << "\n---Match found---" << endl;
                    cout << "IP Address:\t" << curr->getIP() << " occurred:\t"
                         << curr->getCount() << " time(s)." << endl;
                    cout << "(Node: " << curr << ")" << endl;
                    cout << "\nReturning..." << endl;
                    return; // oops
                }
                curr = curr->getNext();
            }
            cout << "\n---No match found---" << endl;
            cout << "Returning..." << endl;
            return;
        }
        default:
            return; // nothing
    }
}