/*
 * File:   EclipseDataDoctor.cpp
 * Author: kflik
 *
 * Created on August 20, 2013, 1:19 PM
 */

#include <iostream>
#include <opm/parser/eclipse/Parser/Parser.hpp>
#include <opm/parser/eclipse/Parser/ParseMode.hpp>
#include <opm/parser/eclipse/Deck/Deck.hpp>
#include <opm/parser/eclipse/EclipseState/Schedule/Schedule.hpp>


int main(int /* argc */, char** argv) {
    Opm::ParseMode parseMode;
    Opm::ParserPtr parser(new Opm::Parser());
    std::string file = argv[1];
    Opm::DeckConstPtr deck = parser->parseFile(file, parseMode);
    std::shared_ptr<const Opm::EclipseGrid> grid = std::make_shared<const Opm::EclipseGrid>( deck );
    Opm::IOConfigPtr ioConfig = std::make_shared<Opm::IOConfig>();
    Opm::Schedule sched( parseMode , grid , deck, ioConfig );

    std::cout << "Wells: " << sched.numWells() << std::endl;


    return 0;
}

