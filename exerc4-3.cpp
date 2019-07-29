#include "screen.h"

// Screen's constructor
Screen::Screen(string::size_type height, string::size_type width, char bkground):
	height_{height},// initialises height_ with height
	width_{width},  // initialises width_ with width
	_screen(height * width, bkground)

{ /* all the work is done in the member initialization list */ }

void Screen::forward()
{   // advance cursor_ one screen element
	++cursor_;

	// wrap around if the cursor_ is at the end of the screen
	if ( cursor_ == _screen.size())
    {
        home();
    }

	return;
}

void Screen::back()
{   // move cursor_ backward one screen element
	// check for top of screen; wrap around
	if ( cursor_ == TOP_LEFT )
		end();
	else
		--cursor_;

	return;
}

void Screen::up()
{   // move cursor_ up one row of screen
	// do not wrap around
	if ( row() == 1 ) // at top?
		end();
	else
		cursor_ -= width_;

	return;
}

void Screen::down(){
	if ( row() == height_ ) // at bottom?
		home();

	else
		cursor_ += width_;

	return;
}

void Screen::move( string::size_type row, string::size_type col )
{   // move cursor_ to absolute position
	// valid screen position?
	if ( checkRange( row, col ) )
	{
		// row location
		int row_loc = (row-1) * width_;
		cursor_ = row_loc + col - 1;
	}

	return;
}

void Screen::move(Direction dir){
    if (dir == DOWN){
        down();

        return;
    } else if(dir == UP){
        up();

        return;
    } else if(dir == FORWARD){
        forward();

        return;
    } else if(dir == BACK){
        back();

        return;
    } else if(dir == HOME){
        home();

        return;
    } else if(dir == END){
        end();

        return;
    }
}

char Screen::get( string::size_type row, string::size_type col )
{
	// position cursor_
	move( row, col );
	// the other get() member function
	return get();                        // HOW IS THIS WORKING? get() vs get(row, col)
}

void Screen::set( char ch )
{
	if ( ch == '\0' )
		cerr << "Screen::set warning: " << "null character (ignored).\n";
	else _screen[cursor_] = ch;

	return;
}

void Screen::set( const string& s )
{   // write string beginning at current cursor_ position
	auto space = remainingSpace();
	auto len = s.size();
	if ( space < len ) {
		cerr << "Screen::set - Truncating, "
			<< "space available: " << space
			<< ", string length: " << len
			<< endl;
		len = space;
	}

	_screen.replace( cursor_, len, s );
	cursor_ += len - 1;

	return;
}

void Screen::clear( char bkground )
{   // reset the cursor and clear the screen
	cursor_ = TOP_LEFT;
	// assign the string
	_screen.assign(
		// with size() characters
		_screen.size(),
		// of value bkground
		bkground
		);

	return;
}

void Screen::reSize( string::size_type h, string::size_type w, char bkground )
{   // can only *increase* a screen's size to height h and width w
	// remember the content of the screen
	string local = _screen;
	int local_pos = TOP_LEFT;

	_screen.assign(
		h * w,
		bkground
		);

	// copy content of old screen into the new one
	for ( string::size_type ix = 0; ix < height_; ++ix )
	{ // for each row
		string::size_type offset = w * ix; // row position
		for ( string::size_type iy = 0; iy < width_; ++iy )
			// for each column, assign the old value
			_screen.at(offset + iy) = local[ local_pos++ ];
	}

	height_ = h;
	width_ = w;
	// cursor_ remains unchanged

	return;
}

void Screen::display() const
{
	for ( string::size_type xIndex = 0; xIndex < height_; ++xIndex )
	{ // for each row
		string::size_type offset = width_ * xIndex; // row position
		for ( string::size_type yIndex = 0; yIndex < width_; ++yIndex )
        {
         // for each column, write element
			cout << _screen[ offset + yIndex ];
        }
		cout << endl;
	}
	return;
}

bool Screen::checkRange( string::size_type row, string::size_type col ) const // CONSTANT MEMBER FUNCTION this function cannot change anything inside itself
                                                                              // it's a read-only file
{
	if (row < 1 || row > height_ || col < 1 || col > width_)
	{
		cerr << "Screen coordinates ("<< row << ", " << col << " ) out of bounds.\n";
		return false;
	}
	return true;
}

string::size_type Screen::remainingSpace() const
{   // includes current position
	int size = width_ * height_;
	return(size - cursor_);
}

string::size_type Screen::row() const
{   // return current row
	return (cursor_ + width_)/width_;
}

