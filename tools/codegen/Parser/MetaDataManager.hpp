/* ----------------------------------------------------------------------------
** © 201x Austin Brunkhorst, All Rights Reserved.
**
** MetaDataManager.h
** --------------------------------------------------------------------------*/

#pragma once

#include "Cursor.hpp"

class ReflectionParser;

class MetaDataManager
{
    typedef std::pair<std::string, std::string> Property;

public:
    MetaDataManager(Cursor const & cursor);

    std::string GetProperty(std::string const & key) const;
    bool GetPropertySafe(std::string const & key, std::string & outValue) const;
    bool HasProperty(std::string const & key) const;

    bool GetFlag(std::string const & key) const;

    std::string GetNativeString(std::string const & key) const;
    

protected:
    std::vector<Property> extractProperties(Cursor const & cursor) const;

private:
    
    std::unordered_map<std::string, std::string> m_properties;

};