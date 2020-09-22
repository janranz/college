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

void addNode(IpNodes** h, string address)
{
    IpNodes* newIP = new IpNodes();
    newIP->setIP(address);
    newIP->setNext(*h);
    *h = newIP;
}

void searchNode(IpNodes* h, string address, int mode)
{
    //Modes: (1) - Tally mode | (2) - Query mode
    switch(mode)
    {
        case 1:
        {
            IpNodes* curr = h;
            string currentIP;
            while(curr != nullptr)
            {
                currentIP = curr->getIP();
                if(currentIP == address)
                {
                    curr->updateCount();
                }
                curr = curr->getNext();
            }
            break;
        }
        case 2:
        {
            // cout << "\n\n---IP Address\t\tOccurred---\n" << endl;
            IpNodes* curr = h;
            while(curr != nullptr)
            {
                cout << "Address:\t" << curr->getIP() << "\tOccurred:\t"
                     << curr->getCount() << " times." << endl;
                curr = curr->getNext();
            }
            break;
        }
        default:
            break; // nothing
    }
}