/*
 *  Copyright (C) 2012 Universidad Simon Bolivar
 * 
 *  Permission is hereby granted to distribute this software for
 *  non-commercial research purposes, provided that this copyright
 *  notice is included with any such distribution.
 *  
 *  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
 *  EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 *  PURPOSE.  THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE
 *  SOFTWARE IS WITH YOU.  SHOULD THE PROGRAM PROVE DEFECTIVE, YOU
 *  ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.
 *  
 *  Blai Bonet, bonet@ldc.usb.ve
 *
 *  Last revision: 11/08/2012
 *
 */

#include <cassert>
#include <iostream>
#include <vector>
#include <stdlib.h>

#define MAX(s,t)      ((s)>(t)?(s):(t))
#define MIN(s,t)      ((s)<(t)?(s):(t))
#define MAXVALUE      1000
#define DIM           36
#define N             6

const int rows[][7] = {
    { 4, 5, 6, 7, 8, 9,-1 }, { 4, 5, 6, 7, 8, 9,-1 }, { 4, 5, 6, 7, 8, 9,-1 },
    { 4, 5, 6, 7, 8, 9,-1 }, { 4, 5, 6, 7, 8, 9,-1 }, { 4, 5, 6, 7, 8, 9,-1 },
    {10,11,12,13,14,15,-1 }, {10,11,12,13,14,15,-1 }, {10,11,12,13,14,15,-1 },
    {10,11,12,13,14,15,-1 }, {10,11,12,13,14,15,-1 }, {10,11,12,13,14,15,-1 },
    {16,17, 0, 1,18,19,-1 }, {16,17, 0, 1,18,19,-1 },
    {16,17, 0, 1,18,19,-1 }, {16,17, 0, 1,18,19,-1 },
    {20,21, 2, 3,22,23,-1 }, {20,21, 2, 3,22,23,-1 },
    {20,21, 2, 3,22,23,-1 }, {20,21, 2, 3,22,23,-1 },
    {24,25,26,27,28,29,-1 }, {24,25,26,27,28,29,-1 }, {24,25,26,27,28,29,-1 },
    {24,25,26,27,28,29,-1 }, {24,25,26,27,28,29,-1 }, {24,25,26,27,28,29,-1 },
    {30,31,32,33,34,35,-1 }, {30,31,32,33,34,35,-1 }, {30,31,32,33,34,35,-1 },
    {30,31,32,33,34,35,-1 }, {30,31,32,33,34,35,-1 }, {30,31,32,33,34,35,-1 }
};
const int cols[][7] = {
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 }, { 6,12, 0, 2,26,32,-1 },
    { 7,13, 1, 3,27,33,-1 }, { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 },
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 }, { 6,12, 0, 2,26,32,-1 },
    { 7,13, 1, 3,27,33,-1 }, { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 },
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 },
    { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 },
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 },
    { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 },
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 }, { 6,12, 0, 2,26,32,-1 },
    { 7,13, 1, 3,27,33,-1 }, { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 },
    { 4,10,16,20,24,30,-1 }, { 5,11,17,21,25,31,-1 }, { 6,12, 0, 2,26,32,-1 },
    { 7,13, 1, 3,27,33,-1 }, { 8,14,18,22,28,34,-1 }, { 9,15,19,23,29,35,-1 }
};
const int dia1[][7] = {
    { 4,11, 0, 3,28,35,-1 }, { 5,12, 1,22,29,-1,-1 }, { 6,13,18,23,-1,-1,-1 },
    { 7,14,19,-1,-1,-1,-1 }, { 8,15,-1,-1,-1,-1,-1 }, { 9,-1,-1,-1,-1,-1,-1 },
    {10,17, 2,27,34,-1,-1 }, { 4,11, 0, 3,28,35,-1 }, { 5,12, 1,22,29,-1,-1 },
    { 6,13,18,23,-1,-1,-1 }, { 7,14,19,-1,-1,-1,-1 }, { 8,15,-1,-1,-1,-1,-1 },
    {16,21,26,33,-1,-1,-1 }, {10,17, 2,27,34,-1,-1 },
    { 6,13,18,23,-1,-1,-1 }, { 7,14,19,-1,-1,-1,-1 },
    {20,25,32,-1,-1,-1,-1 }, {16,21,26,33,-1,-1,-1 },
    { 5,12, 1,22,29,-1,-1 }, { 6,13,18,23,-1,-1,-1 },
    {24,31,-1,-1,-1,-1,-1 }, {20,25,32,-1,-1,-1,-1 }, {16,21,26,33,-1,-1,-1 },
    {10,17, 2,27,34,-1,-1 }, { 4,11, 0, 3,28,35,-1 }, { 5,12, 1,22,29,-1,-1 },
    {30,-1,-1,-1,-1,-1,-1 }, {24,31,-1,-1,-1,-1,-1 }, {20,25,32,-1,-1,-1,-1 },
    {16,21,26,33,-1,-1,-1 }, {10,17, 2,27,34,-1,-1 }, { 4,11, 0, 3,28,35,-1 }
};
const int dia2[][7] = {
    { 4,-1,-1,-1,-1,-1,-1 }, { 5,10,-1,-1,-1,-1,-1 }, { 6,11,16,-1,-1,-1,-1 },
    { 7,12,17,20,-1,-1,-1 }, { 8,13, 0,21,24,-1,-1 }, { 9,14, 1, 2,25,30,-1 },
    { 5,10,-1,-1,-1,-1,-1 }, { 6,11,16,-1,-1,-1,-1 }, { 7,12,17,20,-1,-1,-1 },
    { 8,13, 0,21,24,-1,-1 }, { 9,14, 1, 2,25,30,-1 }, {15,18, 3,26,31,-1,-1 },
    { 6,11,16,-1,-1,-1,-1 }, { 7,12,17,20,-1,-1,-1 },
    {15,18, 3,26,31,-1,-1 }, {19,22,27,32,-1,-1,-1 },
    { 7,12,17,20,-1,-1,-1 }, { 8,13, 0,21,24,-1,-1 },
    {19,22,27,32,-1,-1,-1 }, {23,28,33,-1,-1,-1,-1 },
    { 8,13, 0,21,24,-1,-1 }, { 9,14, 1, 2,25,30,-1 }, {15,18, 3,26,31,-1,-1 },
    {19,22,27,32,-1,-1,-1 }, {23,28,33,-1,-1,-1,-1 }, {29,34,-1,-1,-1,-1,-1 },
    { 9,14, 1, 2,25,30,-1 }, {15,18, 3,26,31,-1,-1 }, {19,22,27,32,-1,-1,-1 },
    {23,28,33,-1,-1,-1,-1 }, {29,34,-1,-1,-1,-1,-1 }, {35,-1,-1,-1,-1,-1,-1 }
};

// moves on the principal variation
static int PV[] = {
    12, 21, 26, 13, 22, 18,  7,  6,  5, 27, 33, 23, 17, 11, 19, 15, 14,
    31, 20, 32, 30, 10, 25, 24, 34, 28, 16,  4, 29, 35, 36,  8,  9, -1
};

class state_t {
    //VARIABLE QUE CONTROLA LAS PERMUTACIONES DE LAS 4 PIEZAS CENTRALES
    unsigned char t_;
    //CONTROLA LAS CASILLAS LIBRES INVERSAMENTE (free_ = 0 ==> TODAS LIBRES)
    //SE BASA EN LAS POTENCIAS DE 2 PARA DETERMINAR CUALES CASILLAS ESTAN LIBRES
    unsigned free_;
    //SIMILAR A FREE, PERO DETERMINA EL COLOR DE LAS FICHAS DADAS UNAS CASILLAS
    //OCUPADAS
    unsigned pos_;

  public:
    //STATE COMIENZA EN LA PERMUTACION 6, LA CUAL CORRESPONDE CON EL ESTADO BASE
    //INICIAL DE UN TABLERO DE OTHELLO. TODAS LAS CASILLAS QUE NO SEAN CENTRALES
    //ESTAN LIBRES
    explicit state_t(unsigned char t = 6) : t_(t), free_(0), pos_(0) { }

    //GETTERS
    unsigned char t() const { return t_; }
    unsigned free() const { return free_; }
    unsigned pos() const { return pos_; }

    //FUNCION DE HASH. EL USO DEL XOR ASEGURA UNIDAD
    size_t hash() const { return free_ ^ pos_ ^ t_; }

    //DETERMINA SI UNA CASILLA(pos) CONTIENE UN COLOR(color) DADO. SI SE LE PASA POS
    //MENOR A 4 RETORNA TRUE DEPENDIENDO SI ALGUNA DE LAS 4 FICHAS CENTRALES ES
    //DE CIERTO COLOR. EJ: SI SE USA TRUE Y 0, SE ESTA DETERMINANDO SI LA FICHA
    //CENTRAL SUPERIOR IZQUIERDA ES NEGRA
    bool is_color(bool color, int pos) const {
        if( color )
            return pos < 4 ? t_ & (1 << pos) : pos_ & (1 << (pos - 4));
        else
            return !(pos < 4 ? t_ & (1 << pos) : pos_ & (1 << (pos - 4)));
    }
    bool is_black(int pos) const { return is_color(true, pos); }
    bool is_white(int pos) const { return is_color(false, pos); }

    //VERIFICA SI UNA CASILLA DADA ESTA LIBRE. DE NUEVO, LOS VALORES MENORES A 4
    //REPRESENTAN LAS CASILLAS CENTRALES. ÉSTAS SIEMPRE ESTAN OCUPADAS
    bool is_free(int pos) const { return pos < 4 ? false : !(free_ & (1 << pos - 4)); }

    //VERIFICA SI EL TABLERO ESTA LLENO. FUNCIONA PORQUE EL MAYOR VALOR QUE
    //free_ PUEDE TOMAR ES 2^32 - 1, QUE ES JUSTAMENTE EL MAYOR UNSIGNED QUE SE
    //PUEDE REPRESENTAR, POR LO TANTO HACER UN NOR LOGICO CAMBIARIA TODOS LOS
    //BITS DE 1 A 0 Y CONVERTIRIA EL NUMERO EN 0
    bool is_full() const { return ~free_ == 0; }

    //CALCULA EL VALOR DE LA HEURISTICA DEL TABLERO
    int value() const;
 
    //DETERMINA SI EL TABLERO ESTA EN UN ESTADO DE FINALIZACION DEL JUEGO
    bool terminal() const;

    //DETERMINA SI COLOCAR UNA FICHA EN ESA POSICION ES LEGAL
    bool outflank(bool color, int pos) const;

    //DETERMINA SI EL MOVIMIENTO ES LEGAL YA SEA PARA LAS NEGRAS O LAS BLANCAS.
    //NOTESE QUE RETORNA TRUE SI POS ES IGUAL A 36, LA CUAL ES UNA CASILLA FUERA
    //DEL TABLERO. ESTO ES ASI PORQUE TAMBIEN EXISTE LA JUGADA DE PASS. LA
    //POSICION 36 TAMBIEN REPRESENTA PASS Y SIEMPRE ES UNA JUGADA LEGAL
    bool is_black_move(int pos) const { return (pos == DIM) || outflank(true, pos); }
    bool is_white_move(int pos) const { return (pos == DIM) || outflank(false, pos); }

    //COLOCA UNA PIEZA DE CIERTO COLOR EN EL TABLERO
    void set_color(bool color, int pos);

    //MUEVE UNA PIEZA EN EL TABLERO(COMPUTA LOS CAMBIOS DE COLOR OCASIONADOS POR
    //UNA JUGADA)
    state_t move(bool color, int pos) const;
    state_t black_move(int pos) { return move(true, pos); }
    state_t white_move(int pos) { return move(false, pos); }

    //OBTIENE UNA JUGADA AL AZAR, CALCULANDO PRIMERO UN VECTOR DE JUGADAS
    //LEGALES
    int get_random_move(bool color) {
        std::vector<int> valid_moves;
        for( int pos = 0; pos < DIM; ++pos ) {
            if( (color && is_black_move(pos)) || (!color && is_white_move(pos)) ) {
                valid_moves.push_back(pos);
            }
        }
        return valid_moves.empty() ? -1 : valid_moves[lrand48() % valid_moves.size()];
    }

    //OPERADOR PARA DETERMINAR SI UN TABLERO ES "MENOR" A OTRO, ES DECIR SI UN
    //TABLERO VA MAS AVANZADO EN JUGADAS QUE OTRO. ESTO SE DETERMINA POR LA
    //CANTIDAD DE PIEZAS EN EL TABLERO
    bool operator<(const state_t &s) const {
        return (free_ < s.free_) || ((free_ == s.free_) && (pos_ < s.pos_));
    }

    //OPERADOR QUE DETERMINA SI DOS TABLEROS SON IGUALES
    bool operator==(const state_t &state) const {
        return (state.t_ == t_) && (state.free_ == free_) && (state.pos_ == pos_);
    }

    //ASIGNA EL CONTENIDO DE UN TABLERO A OTRO TABLERO
    const state_t& operator=(const state_t &state) {
        t_ = state.t_;
        free_ = state.free_;
        pos_ = state.pos_;
        return *this;
    }

    //IMPRIME EL CONTENIDO DEL TABLERO
    void print(std::ostream &os, int depth = 0) const;
    //IMPRIME LA REPRESENTACION DE BITS DE CADA COMPONENTE DEL TABLERO
    void print_bits(std::ostream &os) const;
};

//CALCULA EL VALOR DE LA HEURISTICA DEL TABLERO. PARA HACER ESTO SUMA 1 POR CADA
//PIEZA NEGRA Y RESTA 1 POR CADA PIEZA BLANCA
inline int state_t::value() const {
    int v = 0;
    for( int pos = 0; pos < DIM; ++pos ) {
        if( !is_free(pos) ) v += is_black(pos) ? 1 : -1;
    }
    assert((-36 <= v) && (v <= 36));
    return v;
}

//DETERMINA SI EL JUEGO YA TERMINO. PRIMERO REVISA SI EL TABLERO ESTA LLENO Y
//LUEGO SI HAY MAS JUGADAS LEGALES
inline bool state_t::terminal() const {
    if( is_full() ) return true;
    for( unsigned b = 0; b < DIM; ++b )
        if( is_black_move(b) || is_white_move(b) ) return false;
    return true;
}

//DETERMINA SI LA CASILLA DADA ESTA EN UNA POSICION TAL QUE HAY UNA O MAS FICHAS
//DEL COLOR CONTRARIO HACIA ALGUNOS DE SUS LADOS Y LUEGO HAYA UNA FICHA DEL
//MISMO COLOR DADO. SUPONGO QUE ESTO DETERMINA SI COLOCAR UNA FICHA DEL COLOR
//DADO EN LA CASILLA DADA OCASIONARA CAMBIOS DE COLORES EN LAS FICHAS DEL
//TABLERO POR REGLAS DE OTHELLO. EN OTRAS PALABRAS, DETERMINA SI UN MOVIMIENTO
//DADO ES LEGAL
inline bool state_t::outflank(bool color, int pos) const {
    //SI LA CASILLA ESTA LIBRE, RETORNA FALSO
    if( !is_free(pos) ) return false;

    //VALOR QUE SE USA PARA RECORRER EL TABLERO. ES UN APUNTADOR PORQUE
    //RECORREMOS ARREGLOS
    const int *p = 0;

    // Find if some stones are outflanked

    // Check rows
    //EMPEZAMOS AL INICIO DE LA FILA Y NOS MOVEMOS HACIA LA POSICION EN ESA FILA
    //QUE CONTIENE A LA POSICION QUE COLOCAMOS DE PARAMETRO
    const int *x = rows[pos - 4];
    while( *x != pos ) ++x;

    //SE CHEQUEA QUE NUESTRA CASILLA NO ESTE PEGADA A LA PARED DERECHA DEL
    //TABLERO
    if( *(x+1) != -1 ) {
        //SE CHEQUEA CADA CASILLA A LA DERECHA DE LA NUESTRA, HASTA QUE OCURRA
        //UNA DE TRES COSAS: LLEGAMOS A LA PARED DERECHA, LA CASILLA ESTA LIBRE
        //O LA PIEZA QUE ESTA SEA DEL MISMO COLOR QUE EL COLOR QUE INTRODUJIMOS
        //COMO PARAMETRO
        for( p = x + 1; (*p != -1) && !is_free(*p) && (color ^ is_black(*p)); ++p );
        //EVENTUALMENTE NOS DETENDREMOS EN UNA CASILLA. SI NO ESTAMOS EN LA
        //PARED DERECHA Y LA CASILLA ESTA OCUPADA, DEVOLVEMOS TRUE
        if( (p > x + 1) && (*p != -1) && !is_free(*p) ) return true;
    }

    //SIMILAR AL PASO ANTERIOR, PERO ESTA VEZ SE CHEQUEA SI ESTAMOS EN LA PARED
    //IZQUIERDA, Y VAMOS CHEQUEANDO LAS FICHAS HACIA LA IZQUIERDA
    if( x != rows[pos - 4] ) {
        for( p = x - 1; (p >= rows[pos - 4]) && !is_free(*p) && (color ^ is_black(*p)); --p );
        if( (p < x - 1) && (p >= rows[pos - 4]) && !is_free(*p) ) return true;
    }

    // Check columns
    //SIMILAR A LAS FILAS, PERO CON LAS COLUMNAS
    x = cols[pos - 4];
    while( *x != pos ) ++x;
    if( *(x+1) != -1 ) {
        for( p = x + 1; (*p != -1) && !is_free(*p) && (color ^ is_black(*p)); ++p );
        if( (p > x + 1) && (*p != -1) && !is_free(*p) ) return true;
    }
    if( x != cols[pos - 4] ) {
        for( p = x - 1; (p >= cols[pos - 4]) && !is_free(*p) && (color ^ is_black(*p)); --p );
        if( (p < x - 1) && (p >= cols[pos - 4]) && !is_free(*p) ) return true;
    }

    // [CHECK OVER DIAGONALS REMOVED]

    return false;
}

//COLOCA UNA PIEZA DE CIERTO COLOR EN EL TABLERO. SE EXPLICA LA LOGICA DEL
//ALGORITMO PARA CADA COLOR

//NEGRAS: SI LA CASILLA ES MENOR A 4, ES UNA DE LAS PIEZAS CENTRALES, ES DECIR
//QUE SE DEBE MODIFICAR t_. LA MODIFICACION ES PRENDER EL BIT QUE REPRESENTA A
//LA CASILLA QUE SE QUIERE EN LA CONFIGURACION ACTUAL, LO CUAL SE LOGRA CON UN
//OR. SI LA CASILLA ES MAYOR O IGUAL A 4, SE DEBE PRENDER EL BIT CORRESPONDIENTE
//TANTO EN free_ COMO EN pos_, PUES FREE INDICA QUE HAY UNA PIEZA ALLI Y POS
//INDICA QUE DICHA PIEZA ES NEGRA

//BLANCAS: SI LA CASILLA ES MENOR A 4, SE DEBE APAGAR EL BIT CORRESPONDIENTE,
//POR LO QUE SE USA AND(APAGAR BITS) Y NOR(REVERSAR BITS PARA APAGAR LOS BITS
//CORRECTOS). PARA CASILLAS MAYORES A 4, LA LOGICA ES SIMILAR A CON LAS NEGRAS,
//SOLO QUE PARA EL CASO DE POS SE DEBE APAGAR EL BIT EN LUGAR DE PRENDERLO
inline void state_t::set_color(bool color, int pos) {
    if( color ) {
        if( pos < 4 ) {
            t_ |= 1 << pos;
        } else {
            free_ |= 1 << pos- 4;
            pos_ |= 1 << pos - 4;
        }
    } else {
        if( pos < 4 ) {
            t_ &= ~(1 << pos);
        } else {
            free_ |= 1 << pos - 4;
            pos_ &= ~(1 << pos - 4);
        }
    }
}

//RETORNA EL ESTADO QUE REPRESENTA UNA JUGADA DADA POR EL COLOR Y LA POSICION
//PASADAS COMO ARGUMENTO
inline state_t state_t::move(bool color, int pos) const {
    state_t s(*this);
    //RETORNAR EL MISMO ESTADO SI LA POSICION ES PASS
    if( pos >= DIM ) return s;

    //VERIFICAR QUE LA JUGADA ES LEGAL Y COLOCAR LA PIEZA
    assert(outflank(color, pos));
    s.set_color(color, pos);

    // Flip color of outflanked stones

    // Process rows
    //SE CHEQUEA LA FILA DE LA NUEVA PIEZA COLOCADA. POR CADA PIEZA QUE ESTE
    //ENTRE ESTA NUEVA PIEZA Y LA SIGUIENTE PIEZA DEL MISMO COLOR, SE CAMBIA DE
    //COLOR
    const int *p = 0, *x = rows[pos - 4];
    while( *x != pos ) ++x;
    if( *(x+1) != -1 ) {
        for( p = x + 1; (*p != -1) && !is_free(*p) && (color ^ is_black(*p)); ++p );
        if( (p > x + 1) && (*p != -1) && !is_free(*p) ) {
            for( const int *q = x + 1; q < p; ++q ) s.set_color(color, *q);
        }
    }
    if( x != rows[pos - 4] ) {
        for( p = x - 1; (p >= rows[pos - 4]) && !is_free(*p) && (color ^ is_black(*p)); --p );
        if( (p < x - 1) && (p >= rows[pos - 4]) && !is_free(*p) ) {
            for( const int *q = x - 1; q > p; --q ) s.set_color(color, *q);
        }
    }

    // Process columns
    //SE HACE LO MISMO CON LAS COLUMNAS
    x = cols[pos - 4];
    while( *x != pos ) ++x;
    if( *(x+1) != -1 ) {
        for( p = x + 1; (*p != -1) && !is_free(*p) && (color ^ is_black(*p)); ++p );
        if( (p > x + 1) && (*p != -1) && !is_free(*p) ) {
            for( const int *q = x + 1; q < p; ++q ) s.set_color(color, *q);
        }
    }
    if( x != cols[pos - 4] ) {
        for( p = x - 1; (p >= cols[pos - 4]) && !is_free(*p) && (color ^ is_black(*p)); --p );
        if( (p < x - 1) && (p >= cols[pos - 4]) && !is_free(*p) ) {
            for( const int *q = x - 1; q > p; --q ) s.set_color(color, *q);
        }
    }

    // [PROCESS OF DIAGONALS REMOVED]

    return s;
}

//IMPRIME EL ESTADO DEL TABLERO
inline void state_t::print(std::ostream &os, int depth) const {
    //HEADER
    os << "+";
    for( int j = 0; j < N; ++j ) os << "-";
    os << "+" << std::endl;

    //LA POSICION INICIAL. NOTESE QUE EL CICLO DIFERENCIA ENTRE LAS PIEZAS
    //CENTRALES Y LAS QUE NO LO SON. POR ESO SE EMPIEZA EN 4 Y NO EN 0
    int pos = 4;
    for( int i = 0; i < N; ++i ) {
        os << "|";
        for( int j = 0; j < N; ++j ) {
            if( ((i != 2) && (i != 3)) || ((j != 2) && (j != 3)) ) {
                os << (is_free(pos) ? '.' : (is_black(pos) ? '&' : 'O'));
                ++pos;
            } else {
                assert(((i == 2) || (i == 3)) && ((j == 2) || (j == 3)));
                int p = ((i-2) << 1) + (j-2);
                os << (is_free(p) ? '.' : (is_black(p) ? '&' : 'O'));
            }
        }
        os << "|" << std::endl;
    }

    //FOOTER
    os << "+";
    for( int j = 0; j < N; ++j ) os << "-";
    os << "+" << std::endl;
}

//SE IMPRIME LA REPRESENTACION POR BITS DEL TABLERO. PRIMERO SE IMPRIME t_,
//LUEGO pos_ Y POR ULTIMO free_
inline void state_t::print_bits(std::ostream &os) const {
    for( int i = 3; i >= 0; --i ) os << (t_ & (1 << i) ? '1' : '0');
    os << ":";
    for( int i = 31; i >= 0; --i ) os << (pos_ & (1 << i) ? '1' : '0');
    os << ":";
    for( int i = 31; i >= 0; --i ) os << (free_ & (1 << i) ? '1' : '0');
}

//OVERLOAD DE OPERADOR PARA FACILITAR LA IMPRESION DE DATOS
inline std::ostream& operator<<(std::ostream &os, const state_t &state) {
    state.print(os);
    return os;
}

