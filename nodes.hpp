/*
 * This defines the "node" class in C++. And SOME subclasses.
 * Really to separate the subclasses into "types" of files, like binary
 * operators or math operators and logical operators, and so on. 
 * The commented out portions are for debugging.
 *
 *
 * $Author: kbuckner $
 * $Id: nodes.hpp,v 1.1 2021-09-27 11:38:16-06 kbuckner Exp kbuckner $
 * $Date: 2021-09-27 11:38:16-06 $
 *
 * $Log: nodes.hpp,v $
 * Revision 1.1  2021-09-27 11:38:16-06  kbuckner
 * *** empty log message ***
 *
 *
 */

#ifndef NODES_HPP
#define NODES_HPP
#include <iostream>
#include <string>

using std::endl;
using std::ostream;
using std::string;

class Node
{
public:
    // set the pointers to 0 C++ is trying to get away from NULL
    Node(Node *lf = 0, Node *rt = 0);
    virtual ~Node();
    int getint() const;
    double getdbl() const;
    string getstring() const;
    void setval(const char *v);
    void setval(const string s);
    void setval(int i);
    void setval(double d);
    void setID(const string id);
    void reset();
    void setleft(Node *p);
    void setright(Node *p);
    void setnext(Node *p);
    Node *getleft();
    Node *getright();
    Node *getnext();
    virtual void print(ostream *out = 0);

protected:
    int myline;
    int mycol;
    int ival;
    double dval;
    string sval;
    string idPrev;
    Node *left, *right;
    Node *next;
};

class nodeMinus : public Node
{
public:
    nodeMinus(Node *lf = 0, Node *rt = 0);

    virtual void print(ostream *out = 0);
};

class nodePlus : public Node
{
public:
    nodePlus(Node *lf = 0, Node *rt = 0);

    virtual void print(ostream *out = 0);
};


class nodeNot : public Node
{
public:
    nodeNot(Node *lf = 0, Node *rt = 0);

    virtual void print(ostream *out = 0);
};

class nodeIdMulId : public Node
{
public:
    nodeIdMulId(Node *lf = 0, Node *rt = 0);

    virtual void print(ostream *out = 0);
};


class nodeRead : public Node
{
    public:
        nodeRead();

        virtual void print(ostream *out = 0);
};

class newNodePar : public Node
{
    public:
        newNodePar();

        virtual void print(ostream *out = 0);
};

class newNode : public Node
{
    public:
        newNode(Node *lf = 0, Node *rt = 0);

        virtual void print(ostream *out = 0);
};

class nodeBrackExp : public Node
{
    public:
        nodeBrackExp(Node *lf = 0, Node *rt = 0);

        virtual void print(ostream *out = 0);
};

class nodeInt : public Node
{
    public:
        nodeInt();

        virtual void print(ostream *out = 0);
};

class nodeNum : public Node
{
public:
    nodeNum(int i);
    virtual void print(ostream *out = 0);
};

class nodeParExp : public Node
{
public:
    nodeParExp(Node *lf = 0, Node *rt = 0);
    virtual void print(ostream *out = 0);
};

class nodeNameParen : public Node
{
public:
    nodeNameParen(Node *lf = 0, Node *rt = 0);
    virtual void print(ostream *out = 0);
};

class nodeExpExp : public Node
{
public:
    nodeExpExp(Node *lf = 0, Node *rt = 0);
    virtual void print(ostream *out = 0);
};

#endif
