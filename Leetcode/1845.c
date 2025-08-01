typedef struct {
    int max_seats;
    int* seats;
    int* end_seat;
} SeatManager;


SeatManager* seatManagerCreate(int n) {

    SeatManager* a; // Cria seatManager
    a->max_seats = n; // passa o valor n como maximo de acentos
    a->seats = malloc(sizeof(int) * a->max_seats); // Aloca o espaço de memória necessário para os seats
    for(int i = 0; i < n; i++)
    {
        a->seats[i] = NULL;
    }
    a->end_seat = a->seats; // Aponta para o endereco de memoria 
    return a;

}

int seatManagerReserve(SeatManager* obj) {
    int end_inicial = obj->end_seat;

    
}

void seatManagerUnreserve(SeatManager* obj, int seatNumber) {
    
}

void seatManagerFree(SeatManager* obj) {
    
}

int main(void) {

    SeatManager* seatManager = seatManagerCreate(5); // Initializes a SeatManager with 5 seats.
    seatManagerReserve(seatManager);    // All seats are available, so return the lowest numbered seat, which is 1.
    seatManagerReserve(seatManager);    
    seatManagerUnreserve(seatManager, 2); // Unreserve seat 2, so now the available seats are [2,3,4,5].
    seatManagerReserve(seatManager);     // The available seats are [3,4,5], so return the lowest of them, which is 3.
    seatManagerReserve(seatManager);     // The available seats are [4,5], so return the lowest of them, which is 4.
    seatManagerReserve(seatManager);     // The only available seat is seat 5, so return 5.
    seatManagerReserve(seatManager);     // The available seats are [2,3,4,5], so return the lowest of them, which is 2.
    seatManagerUnreserve(seatManager, 5); // Unreserve seat 5, so now the available seats are [5].

}