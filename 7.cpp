#include <iostream>
#include <vector>
using namespace std;

class Seat
{
public:
    int seatNumber;
    bool isBooked;
    Seat *next;

    Seat(int number) : seatNumber(number), isBooked(false), next(nullptr) {}
};

class Row
{
public:
    Seat *head;

    Row(int seats) : head(nullptr)
    {
        for (int i = 1; i <= seats; ++i)
        {
            Seat *newSeat = new Seat(i);
            if (!head)
            {
                head = newSeat;
                newSeat->next = head;
            }
            else
            {
                Seat *current = head;
                while (current->next != head)
                {
                    current = current->next;
                }
                current->next = newSeat;
                newSeat->next = head;
            }
        }
    }

    void displayAvailableSeats()
    {
        Seat *current = head;

        do
        {
            if (!current->isBooked)
            {
                cout << "Seat " << current->seatNumber << " ";
            }
            current = current->next;
        } while (current != head);

        cout << endl;
    }

    void bookSeat(int seatNumber)
    {
        Seat *current = head;

        do
        {
            if (current->seatNumber == seatNumber && !current->isBooked)
            {
                current->isBooked = true;
                cout << "Seat " << seatNumber << " booked successfully." << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Seat " << seatNumber << " not available." << endl;
    }

    void cancelBooking(int seatNumber)
    {
        Seat *current = head;

        do
        {
            if (current->seatNumber == seatNumber && current->isBooked)
            {
                current->isBooked = false;
                cout << "Booking for seat " << seatNumber << " canceled successfully." << endl;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << "Seat " << seatNumber << " is not booked." << endl;
    }
};

class CinemaxBookingSystem
{
private:
    vector<Row *> rows;

public:
    CinemaxBookingSystem(int numRows, int seatsPerRow)
    {
        for (int i = 0; i < numRows; ++i)
        {
            rows.push_back(new Row(seatsPerRow));
        }
    }

    void displayAvailableSeats()
    {
        cout << "Available Seats:\n";
        for (int i = 0; i < rows.size(); ++i)
        {
            cout << "Row " << i + 1 << ": ";
            rows[i]->displayAvailableSeats();
        }
    }

    void bookSeat(int rowNumber, int seatNumber)
    {
        if (rowNumber >= 1 && rowNumber <= rows.size())
        {
            rows[rowNumber - 1]->bookSeat(seatNumber);
        }
        else
        {
            cout << "Invalid row number.\n";
        }
    }

    void cancelBooking(int rowNumber, int seatNumber)
    {
        if (rowNumber >= 1 && rowNumber <= rows.size())
        {
            rows[rowNumber - 1]->cancelBooking(seatNumber);
        }
        else
        {
            cout << "Invalid row number.\n";
        }
    }
};

int main()
{
    CinemaxBookingSystem cinema(10, 7);

    while (true)
    {
        cout << "\nCinemax Ticket Booking System:\n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cinema.displayAvailableSeats();
            break;

        case 2:
            cout << "Enter row and seat number to book (e.g., 3 5): ";
            int bookRow, bookSeat;
            cin >> bookRow >> bookSeat;
            cinema.bookSeat(bookRow, bookSeat);
            break;

        case 3:
            cout << "Enter row and seat number to cancel booking (e.g., 3 5): ";
            int cancelRow, cancelSeat;
            cin >> cancelRow >> cancelSeat;
            cinema.cancelBooking(cancelRow, cancelSeat);
            break;

        case 4:
            cout << "Exiting program.\n";
            return 0;

        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
