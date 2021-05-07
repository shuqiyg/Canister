/* W04 LAB
   Name: Shuqi Yang
   Std ID: 132162207
   Email: syang136@myseneca.ca
   Date: 02-09-2021
   -------------------------------------------------------
   I have done all the coding by myself and only copied the
   code that my professor provided to complete my workshops
   and assignments.
 */
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
#define PI 3.14159265
using namespace std;
namespace sdds {

    void Canister::setToDefault() {
        m_contentName = nullptr;
        m_diameter = 10.0f;
        m_height = 13.0f;
        m_contentVolume = 0.0f;
        m_usable = true;
    }
    void Canister::setName(const char* Cstr) {
        if (Cstr != nullptr && isEmpty() && m_contentVolume/PI/((m_diameter/2)*(m_diameter/2)) < m_height - .267) {
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
        }
    }
    bool Canister::isEmpty()const {
        if (m_contentVolume < 0.00001) {
            return true;
        }
        return false;
    }
    bool Canister::hasSameContent(const Canister& C)const {
        if (m_contentName != nullptr && C.m_contentName != nullptr) {
            if (strCmp(m_contentName, C.m_contentName) == 0) {
                return true;
            }
        }
        return false;
    }
    Canister::Canister() {
        setToDefault();
    }
    Canister::Canister (const char* contentName) {
        setToDefault();
        setName(contentName);
    }
    Canister::Canister(double height, double diameter,
        const char* contentName ) {
        setToDefault();
        if (height >= 10.0 && height <= 40.0 && diameter >= 10.0 && diameter <= 30) {
            m_height = height;
            m_diameter = diameter;
            setName(contentName);
            m_contentVolume = 0;
        }
        else {
            m_usable = false;
        }
    }
    Canister::~Canister() {
        delete[] m_contentName;
        m_contentName = nullptr;
    }
    Canister& Canister::setContent(const char* contentName) {
        if (contentName == nullptr) {
            m_usable = false;
        }
        else if (isEmpty()) {
            setName(contentName);
        }
        else if (strCmp(m_contentName, contentName) != 0) {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity) {
        bool lessOrEq = ((quantity + m_contentVolume) <= capacity());
        if (quantity > 0 && m_usable && lessOrEq) {
            m_contentVolume += quantity;
        }
        else {
            m_usable = false;
        }
        return *this;
   }
    Canister& Canister::pour(Canister& C) {
        if (!hasSameContent(C) && !isEmpty()) {
           m_usable = false;
        }     
        setContent(C.m_contentName);      
        if (C.volume() > (capacity() - volume())) {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    double Canister::volume()const {
        return m_contentVolume;
    }
    ostream& Canister::display()const {
        cout.width(7);
        cout.precision(1);
        cout.setf(ios::fixed);
        cout << capacity() << "cc (" << m_height << "x" << m_diameter << ") Canister";
        if (!m_usable) {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr) {         
            cout << " of ";
            cout.width(7);
            cout << m_contentVolume << "cc   " << m_contentName;
        }
        return cout;

    }
    double Canister::capacity()const {
        return PI * (m_height - 0.267) * (m_diameter / 2) * (m_diameter / 2);
    }
    void Canister::clear() {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true;
    }
}
