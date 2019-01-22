#include "history.hpp"

const int History::DEF_VALUE = -1;

History::History()
{
    selectedCell = QPoint(DEF_VALUE, DEF_VALUE);
    stackAdded = DEF_VALUE;
    start = false;
    inputIndexChanged = false;
    removeHappened = false;
}

bool History::isSelectedCell()
{
    return selectedCell.x() != DEF_VALUE && selectedCell.y() != DEF_VALUE;
}

bool History::isStackAdded()
{
    return stackAdded != DEF_VALUE;
}

bool History::isStart()
{
    return start;
}

bool History::isInputIndexChanged()
{
    return inputIndexChanged;
}


bool History::isStackRemoved()
{
    return removeHappened;
}

int History::getStackRemoved()
{
    return stackRemoved;
}

void History::setStackRemoved(int removed)
{
    stackRemoved = removed;
    removeHappened = true;
}