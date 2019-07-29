#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

class Screen {

private:

	const string::size_type TOP_LEFT = 0;
	string::size_type remainingSpace() const;
    string::size_type row() const;
    //string::size_type col();
	string::size_type height_;
	string::size_type width_;
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;

public:

	Screen(string::size_type height, string::size_type width, char bkground = '#');
	// get the Screen's height
	string::size_type height() const { return height_; }   // CONSTANT MEMBER FUNCTION this function cannot change anything inside itself
                                                           // it's a read-only file
	// get the Screen's width
	string::size_type width() const { return width_; }     // CONSTANT MEMBER FUNCTION this function cannot change anything inside itself

	void home() { cursor_ = 0;  return; }
	void end() { cursor_ = width_ * height_ - 1; return; }
	void forward();
	void back();
	void up();
	void down();
	void move(string::size_type row, string::size_type col);
	enum Direction{UP, DOWN, FORWARD, BACK, HOME, END};

	void move(Direction dir);
	char get() const { return _screen[cursor_]; }// CONSTANT MEMBER FUNCTION this function cannot change anything inside itself
                                                 // it's a read-only file
	char get(string::size_type row, string::size_type col);

	void set(char ch);

	void set( const string& s ); // CONSTANT MEMBER (string) this string cannot be changed inside this function

	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');
	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;

};

#endif

