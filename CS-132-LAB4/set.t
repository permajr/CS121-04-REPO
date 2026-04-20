// File: set.t
// Course: CS132 Lab4
// Semester: sp2026
// Programmer: Randy Devlin-Souter
// Description: Set class template definition



template <class Universe>
Set<Universe>::Set(Universe lo, Universe hi) :
    Array_V<Universe, bool>(lo, hi)
{
    loElement = lo;
    hiElement = hi;
    for (Universe element = loElement; element <= hiElement; ++element)
        (*this)[element] = false;

}


template <class Universe>
Set <Universe>::Set(Set<Universe>& initSet)
    :Array_V<Universe, bool>(initSet.loElement, initSet.hiElement)
{
    loElement = initSet.loElement;
    hiElement = initSet.hiElement;

    for (Universe element = loElement; element <= hiElement; ++element)
    {
        (*this)[element] = initSet[element];
    }
}


template<class Universe>
Set <Universe> Set<Universe>::operator || (Set<Universe>& t)
{
    Set<Universe> temp(loElement, hiElement);
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " && invalid ranges" << endl;
        return (*this);
    }
    else for (Universe u = loElement; u <= hiElement; ++u)
        temp[u] = ((*this)[u] || t[u]);
    return temp;
}

template<class Universe>
Set <Universe> Set<Universe>::operator && (Set<Universe>& t)
{
    Set<Universe> temp(loElement, hiElement);
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " && invalid ranges" << endl;
        return (*this);
    }
    else for (Universe u = loElement; u <= hiElement; ++u)
        temp[u] = ((*this)[u] && t[u]);
    return temp;
}

template <class Universe>
Set<Universe>::~Set()
{
}
template <class Universe>
void Set<Universe>:: operator = (Set<Universe>&& source)
{
    if ((loElement != source.loElement) || (hiElement != source.hiElement))
        cout << " invalid assignment: incompatable ranges " << endl;

    else
        for (Universe el = loElement; el <= hiElement; el++)
            (*this)[el] = source[el];
}

template <class Universe>
bool Set<Universe>::empty()
{
    bool temp = true;
    for (Universe el = loElement; el <= hiElement; el++)
        if ((*this)[el]) temp = false;
    return temp;
}

template <class Universe>
bool Set<Universe>::operator == (Set<Universe>& t)
{
    bool temp = true;
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " == invalid ranges" << endl;
        return false;
    }
    else
    {
        for (Universe el = loElement; el <= hiElement; el++)
            if ((*this)[el] != t[el])
                temp = false;
        return temp;
    }
}


template <class Universe>
bool Set<Universe>::operator <= (Set<Universe>& t)
{
    bool temp = true;
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " <= invalid ranges" << endl;
        return false;
    }
    else
    {
        for (Universe el = loElement; el <= hiElement; el++)
            if ((*this)[el] && (!t[el]))
                temp = false;
        return temp;
    }
}



template <class Universe>
void Set<Universe>::add(Universe el)
{
    (*this).assign(el, true);
}

template <class Universe>
void Set<Universe>::remove(Universe el)
{
    (*this)[el] = false;
}

template <class Universe>
void Set<Universe>::writeSet()
{
    bool comma = false;
    cout << '{';
    for (Universe el = loElement; el <= hiElement; el++)
    {
        if (comma && (*this)[el]) cout << ',';
        if ((*this)[el])
        {
            cout << el;
            comma = true;
        }
    }
    cout << '}' << endl;

}

template <class Universe>
bool Set<Universe>::inSet(Universe element)
{
    return (*this)[element];
}

template<class Universe>
Set<Universe> Set<Universe>::operator - (Set<Universe>& t)
{
    Set<Universe> temp(loElement, hiElement);
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " - invalid ranges" << endl;
        return (*this);
    }
    else
        for (Universe u = loElement; u <= hiElement; ++u)
            temp[u] = ((*this)[u] && !t[u]);
    return temp;
}

template<class Universe>
Set<Universe> Set<Universe>::operator / (Set<Universe>& t)
{
    Set<Universe> temp(loElement, hiElement);
    if ((loElement != t.loElement) || (hiElement != t.hiElement))
    {
        cout << " / invalid ranges" << endl;
        return (*this);
    }
    else
        for (Universe u = loElement; u <= hiElement; ++u)
            temp[u] = (((*this)[u] || t[u]) && !((*this)[u] && t[u]));
    return temp;
}

#include "array_v.t"