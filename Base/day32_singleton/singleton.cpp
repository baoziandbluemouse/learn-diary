//
// Created by baozi on 2025/8/23.
//

#include "singleton.h"

//SignleHungry* SignleHungry::instance = SignleHungry::GetInst();
//SingleLazy* SingleLazy::instance = nullptr;
//std::mutex SingleLazy::_mutex;
std::shared_ptr<Singleflag> Singleflag::instance = nullptr;
