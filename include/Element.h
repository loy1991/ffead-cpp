/*
	Copyright 2009-2012, Sumeet Chhetri 
  
    Licensed under the Apache License, Version 2.0 (the "License"); 
    you may not use this file except in compliance with the License. 
    You may obtain a copy of the License at 
  
        http://www.apache.org/licenses/LICENSE-2.0 
  
    Unless required by applicable law or agreed to in writing, software 
    distributed under the License is distributed on an "AS IS" BASIS, 
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
    See the License for the specific language governing permissions and 
    limitations under the License.  
*/

#ifndef ELEMENT_H_
#define ELEMENT_H_


#include "map"
#include "vector"
#include "StringUtil.h"
#include "string"
#include "Renderer.h"
#include <iostream>
using namespace std;


class Element : public Renderer
{
public:
	Element();
	~Element();
	typedef map<string,string> AttributeList;
	typedef map<string,Element> ElementMap;
	typedef vector<Element> ElementList;
	void addElement(Element element);
	void removeElement(Element element);
	void updateElement(Element);
	void addAttribute(string key,string value,bool validate = false);
	void removeAttribute(string key);
	AttributeList getAttributes();
	string getAttribute(string);
	ElementList getChildElements();
	bool isNull();
	string getTagName();
	string getTagNameSpc();
	string getNameSpc();
	void setTagName(string tagName);
	bool operator == (Element);
	bool operator == (Element *);
	bool getCdata() const;
	void setCdata(bool);
	string getText() const;
	void setText(string);
	Element getElementByName(string);
	ElementList getElementsByName(string name);
	string render();
	string renderSerialization();
	string renderChildren();
	void validateNs();
	string getNameSpcValue();
private:
	bool isValidNamespace(Element* ele, string nameSpace);
	string getNmspc(Element* ele, string nameSpace);
	Element* parent;
	AttributeList attributes;
	AttributeList namespaces;
	AttributeList allnmspcs;
	ElementList elements;
	string tagName;
	string nameSpace;
	string text;
	bool cdata;
	ElementMap mapOfEle;
	friend class Document;
};
#endif


