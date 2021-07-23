#include "controller.h"
#include <iostream>

/**
 * @brief Construct a new Controller:: Controller object based on the options the user selects in the title page
 * It also initializes model and view objects and registers the view as an oberver to the model
 * 
 * It has the main game loop of the application
 * 
 * @param options This variable tells the mode of gameplay the user has selected in the title page.
 */
Controller::Controller(int options) : model(), view(DEFAULT_BOARD_SIZE)
{
    decideAI(options);
    model.registerObserver(&view);
    view.updateBoard(model.boardConfiguration);
    view.updateMoveHistory(piece::EMPTY, "");
    view.updateScore(model.blackScore, model.whiteScore);
    connect_bitmap_buttons();
    connect_other_buttons();
    // view.gui2.mainLoop();
    while(view.window2.isOpen())
    {
        sf::Event event;
        while (view.window2.pollEvent(event))
        {
        view.gui2.handleEvent(event);

        if (event.type == sf::Event::Closed)
            view.window2.close();
        }
        view.window2.clear();
        view.gui2.draw();
        view.window2.display();
    }
}

/**
 * @brief This functions selects the type of AI(Random, Greedy, NoAI) based on option selected by the user.
 * 
 * @param options This variable tells the mode of gameplay the user has selected in the title page.
 */
void Controller::decideAI(int options)
{
    switch(options)
    {
        case 1 : AIplayer = new NoAI();         break;
        // case 2 : AIplayer = new RandAI();       break;
        case 3 : AIplayer = new GreedyAI();     break;
        // case 4 : AIplayer = new MinimaxAI();    break;
        default : AIplayer = new NoAI();
    }
}

/**
 * @brief This function connects each of the 64 board buttons in view to a corresponding action in the model
 * 
 * This function is the main connection between the controller and the model, it captures the user interactions 
 * and sends it to the model (which has the game logic).
 * 
 */
void Controller::connect_bitmap_buttons()
{

    for(unsigned int i = 0; i<DEFAULT_BOARD_SIZE; i++)
    {
        for(unsigned int j = 0; j<DEFAULT_BOARD_SIZE; j++)
        {
            view.cellButtons[i][j]->onPress([=, this]() {

                if(model.isLegal(std::make_pair(i, j)))
                {
                    updateGameState(std::make_pair(i, j));
                    AIPlay(model);
                }
                });
        }
    }
}

/**
 * @brief This function connects the other buttons of the view (New Game, Quit, Pass, Main Menu) to a corresponding action.
 * 
 */

void Controller::connect_other_buttons()
{
    view.passButton->onPress([&]() {
        model.pass_count++;
        model.movePassed();
        model.updateBoard();
        if(model.pass_count==2)
        {
            model.message = 3;
        }
        model.notifyObservers();
        model.switchPlayer();
        AIPlay(model);
    });

    view.quitButton->onPress([&]() {
        view.window2.close();
    });

    view.newGameButton->onPress([&]() {
        model.reset();

        view.moveHistory->removeAllLines();
        view.updateBoard(model.boardConfiguration);
        view.updateMoveHistory(piece::EMPTY, "");
        view.updateScore(model.blackScore, model.whiteScore);
    });

    view.mainMenu->onPress([&]() {
        view.window2.close();
    });

    view.newGame->onPress([&]() {
        // Reset the entire game!!!
        model.reset();
        view.gui2.remove(view.gameOver);
        view.moveHistory->removeAllLines();
        view.updateBoard(model.boardConfiguration);
        view.updateMoveHistory(piece::EMPTY, "");
        view.updateScore(model.blackScore, model.whiteScore);
    });
}

/**
 * @brief This function gets a coordinate from the user and passes it to the model to update the game state.
 * 
 * @param coord This variable is the coordinate of the square the user has clicked on.
 */
void Controller::updateGameState(std::pair<unsigned int, unsigned int> coord)
{
    model.pass_count = 0;
    model.placeMove(coord);
    model.updateBoard();
    model.notifyObservers();
    model.switchPlayer();
}

/**
 * @brief This function lets the AI play after every move the player makes.
 * 
 * If the AI is NoAI, the program waits until the second player has made a move. 
 * Otherwise, it makes a move as soon as the first player makes a move,
 * 
 * @param board This is the model of the game. It has data about the present board configuration, 
 * the valid moves that AI can make, so that the AI can select the required move and place the move.
 */

void Controller::AIPlay(OthelloBoard board)
{
    std::pair<unsigned int, unsigned int> coord = AIplayer->play(board);
    if(coord != INVALID_COORD)
    {
        updateGameState(coord);
    }
}
