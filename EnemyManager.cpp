#include "pch.h"
#include "EnemyManager.h"
#include "Enemy.h"

HRESULT EnemyManager::init()
{
    //루크 이미지 저장소
#pragma region LUKEIMAGES

    IMAGEMANAGER->addFrameImage("LUKE_INIT", "LUKE/LUKE_INIT.bmp", 240, 480, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_IDLE", "LUKE/LUKE_IDLE.bmp", 2880, 480, 12, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_WALK", "LUKE/LUKE_WALK.bmp", 4320, 480, 18, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_RUN", "LUKE/LUKE_RUN.bmp", 5760, 480, 24, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_JUMP", "LUKE/LUKE_JUMP.bmp", 2400, 480, 10, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_ATTACK1", "LUKE/LUKE_ATTACK1.bmp", 1920, 480, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_ATTACK2", "LUKE/LUKE_ATTACK2.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_ATTACK3", "LUKE/LUKE_ATTACK3.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_DAMAGED", "LUKE/LUKE_DAMAGED.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_DOWN", "LUKE/LUKE_DOWN.bmp", 3360, 480, 14, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_DOWN_DAMAGED", "LUKE/LUKE_DOWN_DAMAGED.bmp", 960, 480, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_UP", "LUKE/LUKE_UP.bmp", 1920, 480, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_GUARD", "LUKE/LUKE_GUARD.bmp", 720, 480, 3, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_OBJECT_ATTACK", "LUKE/LUKE_OBJECT_ATTACK.bmp", 2880, 480, 12, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_OBJECT_THROW_SELF_DAMAGED", "LUKE/LUKE_OBJECT_THROW_SELF_DAMAGED.bmp", 3120, 480, 13, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("LUKE_OBJECT_GRAB", "LUKE/LUKE_OBJECT_GRAB.bmp", 1200, 480, 5, 2, true, RGB(255, 0, 255));

#pragma endregion

    //마이크 이미지 저장소
#pragma region MIKEIMAGES
    IMAGEMANAGER->addFrameImage("MIKE_INIT", "MIKE/MIKE_INIT.bmp", 240, 480, 1, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_IDLE", "MIKE/MIKE_IDLE.bmp", 2880, 480, 12, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_WALK", "MIKE/MIKE_WALK.bmp", 4320, 480, 18, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_RUN", "MIKE/MIKE_RUN.bmp", 5760, 480, 24, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_JUMP", "MIKE/MIKE_JUMP.bmp", 2160, 480, 9, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_ATTACK1", "MIKE/MIKE_ATTACK1.bmp", 1920, 480, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_ATTACK2", "MIKE/MIKE_ATTACK2.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_ATTACK3", "MIKE/MIKE_ATTACK3.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_DAMAGED", "MIKE/MIKE_DAMAGED.bmp", 1680, 480, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_DOWN", "MIKE/MIKE_DOWN.bmp", 3360, 480, 14, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_DOWN_DAMAGED", "MIKE/MIKE_DOWN_DAMAGED.bmp", 960, 480, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_UP", "MIKE/MIKE_UP.bmp", 1920, 480, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_GUARD", "MIKE/MIKE_GUARD.bmp", 720, 480, 3, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_OBJECT_ATTACK", "MIKE/MIKE_OBJECT_ATTACK.bmp", 2880, 480, 12, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_OBJECT_THROW_SELF_DAMAGED", "MIKE/MIKE_OBJECT_THROW_SELF_DAMAGED.bmp", 3120, 480, 13, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MIKE_OBJECT_GRAB", "MIKE/MIKE_OBJECT_GRAB.bmp", 1200, 480, 5, 2, true, RGB(255, 0, 255));
#pragma endregion

    //말콤 이미지 저장소
#pragma region MALCOLMIMAGES

    IMAGEMANAGER->addFrameImage("MALCOLM_IDLE", "MALCOLM/MALCOLM_IDLE.bmp", 1400, 700, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_WALK", "MALCOLM/MALCOLM_WALK.bmp", 2800, 700, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_RUN", "MALCOLM/MALCOLM_RUN.bmp", 2800, 700, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_JUMP", "MALCOLM/MALCOLM_JUMP.bmp", 4550, 700, 13, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_ATTACK1", "MALCOLM/MALCOLM_ATTACK1.bmp", 3150, 700, 9, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_ATTACK2", "MALCOLM/MALCOLM_ATTACK2.bmp", 1400, 700, 4, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_ATTACK3", "MALCOLM/MALCOLM_ATTACK3.bmp", 1750, 700, 5, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_ATTACK4", "MALCOLM/MALCOLM_ATTACK4.bmp", 2800, 700, 8, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_DAMAGED", "MALCOLM/MALCOLM_DAMAGED.bmp", 2450, 700, 7, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_DOWN", "MALCOLM/MALCOLM_DOWN.bmp", 4900, 700, 14, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_DOWN_DAMAGED", "MALCOLM/MALCOLM_DOWN_DAMAGED.bmp", 1750, 700, 5, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_DOWN_ATTACK", "MALCOLM/MALCOLM_DOWN_ATTACK.bmp", 1750, 700, 5, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_UP", "MALCOLM/MALCOLM_UP.bmp", 3150, 700, 9, 2, true, RGB(255, 0, 255));
    IMAGEMANAGER->addFrameImage("MALCOLM_GUARD", "MALCOLM/MALCOLM_GUARD.bmp", 700, 700, 2, 2, true, RGB(255, 0, 255));

#pragma endregion

    //루크 애니메이션 저장소
#pragma region LUKEANIMATIONS
    int LUKEleftInit[] = { 0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftInit", "LUKE_INIT", LUKEleftInit, 1, 6, true);
    int LUKErightInit[] = { 1 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightInit", "LUKE_INIT", LUKErightInit, 1, 6, true);
    int LUKEleftIdle[] = { 11,10,9,8,7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftIdle", "LUKE_IDLE", LUKEleftIdle, 8, 6, true);
    int LUKErightIdle[] = { 12,13,14,15,16,17,18,19 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightIdle", "LUKE_IDLE", LUKErightIdle, 8, 6, true);
    int LUKEleftWalk[] = { 17,16,15,14,13,12,11,10,9,8,7,6 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftWalk", "LUKE_WALK", LUKEleftWalk, 12, 6, true);
    int LUKErightWalk[] = { 18,19,20,21,22,23,24,25,26,27,28,29 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightWalk", "LUKE_WALK", LUKErightWalk, 12, 6, true);
    int LUKEleftRun[] = { 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftRun", "LUKE_RUN", LUKEleftRun, 16, 6, true);
    int LUKErightRun[] = { 24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightRun", "LUKE_RUN", LUKErightRun, 16, 6, true);
    int LUKEleftJump[] = { 9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftJump", "LUKE_JUMP", LUKEleftJump, 10, 6, true);
    int LUKErightJump[] = { 10,11,12,13,14,15,16,17,18,19 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightJump", "LUKE_JUMP", LUKErightJump, 10, 6, true);
    int LUKEleftAttack1[] = { 7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftAttack1", "LUKE_ATTACK1", LUKEleftAttack1, 4, 6, false);
    int LUKErightAttack1[] = { 8,9,10,11 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightAttack1", "LUKE_ATTACK1", LUKErightAttack1, 4, 6, false);
    int LUKEleftAttack2[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftAttack2", "LUKE_ATTACK1", LUKEleftAttack2, 4, 6, false);
    int LUKErightAttack2[] = { 12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightAttack2", "LUKE_ATTACK1", LUKErightAttack2, 4, 6, false);
    int LUKEleftAttack3[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftAttack3", "LUKE_ATTACK2", LUKEleftAttack3, 7, 6, false);
    int LUKErightAttack3[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightAttack3", "LUKE_ATTACK2", LUKErightAttack3, 7, 6, false);
    int LUKEleftAttack4[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftAttack4", "LUKE_ATTACK3", LUKEleftAttack4, 7, 6, false);
    int LUKErightAttack4[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightAttack4", "LUKE_ATTACK3", LUKErightAttack4, 7, 6, false);
    int LUKEleftDamaged[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftDamaged", "LUKE_DAMAGED", LUKEleftDamaged, 7, 6, false);
    int LUKErightDamaged[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightDamaged", "LUKE_DAMAGED", LUKErightDamaged, 7, 6, false);
    int LUKEleftDown[] = { 13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftDown", "LUKE_DOWN", LUKEleftDown, 14, 6, false);
    int LUKErightDown[] = { 14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightDown", "LUKE_DOWN", LUKErightDown, 14, 6, false);
    int LUKEleftDown_Damaged[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftDown_Damaged", "LUKE_DOWN_DAMAGED", LUKEleftDown_Damaged, 4, 6, false);
    int LUKErightDown_Damaged[] = { 4,5,6,7 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightDown_Damaged", "LUKE_DOWN_DAMAGED", LUKErightDown_Damaged, 4, 6, false);
    int LUKEleftUp[] = { 7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftUp", "LUKE_UP", LUKEleftUp, 8, 6, false);
    int LUKErightUp[] = { 8,9,10,11,12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightUp", "LUKE_UP", LUKErightUp, 8, 6, false);
    int LUKEleftGuard[] = { 2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftGuard", "LUKE_GUARD", LUKEleftGuard, 3, 6, false);
    int LUKErightGuard[] = { 3,4,5 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightGuard", "LUKE_GUARD", LUKErightGuard, 3, 6, false);
    int LUKEleftObject_Hang[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftObject_Hang", "LUKE_IDLE", LUKEleftObject_Hang, 4, 6, true);
    int LUKErightObject_Hang[] = { 20,21,22,23 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightObject_Hang", "LUKE_IDLE", LUKErightObject_Hang, 4, 6, true);
    int LUKEleftObject_Attack[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftObject_Attack", "LUKE_OBJECT_ATTACK", LUKEleftObject_Attack, 7, 6, true);
    int LUKErightObject_Attack[] = { 17,18,19,20,21,22,23 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightObject_Attack", "LUKE_OBJECT_ATTACK", LUKErightObject_Attack, 7, 6, true);
    int LUKEleftObject_Throw[] = { 11,10,9,8,7 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleftObject_Throw", "LUKE_OBJECT_ATTACK", LUKEleftObject_Throw, 5, 6, true);
    int LUKErightObject_Throw[] = { 12,13,14,15,16 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKErightObject_Throw", "LUKE_OBJECT_ATTACK", LUKErightObject_Throw, 5, 6, true);
    int LUKEleft_Big_Object_Grab[] = { 4,3 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleft_Big_Object_Grab", "LUKE_OBJECT_GRAB", LUKEleft_Big_Object_Grab, 2, 6, true);
    int LUKEright_Big_Object_Grab[] = { 5,6 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEright_Big_Object_Grab", "LUKE_OBJECT_GRAB", LUKEright_Big_Object_Grab, 2, 6, true);
    int LUKEleft_Small_Object_Grab[] = { 2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEleft_Small_Object_Grab", "LUKE_OBJECT_GRAB", LUKEleft_Small_Object_Grab, 3, 6, true);
    int LUKEright_Small_Object_Grab[] = { 7,8,9 };
    KEYANIMANAGER->addArrayFrameAnimation("LUKEright_Small_Object_Grab", "LUKE_OBJECT_GRAB", LUKEright_Small_Object_Grab, 3, 6, true);
#pragma endregion

    //마이크 애니메이션 저장소
#pragma region MIKEANIMATIONS
    int MIKEleftInit[] = { 0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftInit", "MIKE_INIT", MIKEleftInit, 1, 6, true);
    int MIKErightInit[] = { 1 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightInit", "MIKE_INIT", MIKErightInit, 1, 6, true);
    int MIKEleftIdle[] = { 11,10,9,8,7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftIdle", "MIKE_IDLE", MIKEleftIdle, 8, 6, true);
    int MIKErightIdle[] = { 12,13,14,15,16,17,18,19 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightIdle", "MIKE_IDLE", MIKErightIdle, 8, 6, true);
    int MIKEleftWalk[] = { 17,16,15,14,13,12,11,10,9,8,7,6 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftWalk", "MIKE_WALK", MIKEleftWalk, 12, 6, true);
    int MIKErightWalk[] = { 18,19,20,21,22,23,24,25,26,27,28,29 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightWalk", "MIKE_WALK", MIKErightWalk, 12, 6, true);
    int MIKEleftRun[] = { 23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftRun", "MIKE_RUN", MIKEleftRun, 16, 6, true);
    int MIKErightRun[] = { 24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightRun", "MIKE_RUN", MIKErightRun, 16, 6, true);
    int MIKEleftJump[] = { 8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftJump", "MIKE_JUMP", MIKEleftJump, 9, 6, true);
    int MIKErightJump[] = { 9,10,11,12,13,14,15,16,17 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightJump", "MIKE_JUMP", MIKErightJump, 9, 6, true);
    int MIKEleftAttack1[] = { 7,6,5,4 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftAttack1", "MIKE_ATTACK1", MIKEleftAttack1, 4, 6, false);
    int MIKErightAttack1[] = { 8,9,10,11 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightAttack1", "MIKE_ATTACK1", MIKErightAttack1, 4, 6, false);
    int MIKEleftAttack2[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftAttack2", "MIKE_ATTACK1", MIKEleftAttack2, 4, 6, false);
    int MIKErightAttack2[] = { 12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightAttack2", "MIKE_ATTACK1", MIKErightAttack2, 4, 6, false);
    int MIKEleftAttack3[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftAttack3", "MIKE_ATTACK2", MIKEleftAttack3, 7, 6, false);
    int MIKErightAttack3[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightAttack3", "MIKE_ATTACK2", MIKErightAttack3, 7, 6, false);
    int MIKEleftAttack4[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftAttack4", "MIKE_ATTACK3", MIKEleftAttack4, 7, 6, false);
    int MIKErightAttack4[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightAttack4", "MIKE_ATTACK3", MIKErightAttack4, 7, 6, false);
    int MIKEleftDamaged[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftDamaged", "MIKE_DAMAGED", MIKEleftDamaged, 7, 6, false);
    int MIKErightDamaged[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightDamaged", "MIKE_DAMAGED", MIKErightDamaged, 7, 6, false);
    int MIKEleftDown[] = { 13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftDown", "MIKE_DOWN", MIKEleftDown, 14, 6, false);
    int MIKErightDown[] = { 14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightDown", "MIKE_DOWN", MIKErightDown, 14, 6, false);
    int MIKEleftDown_Damaged[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftDown_Damaged", "MIKE_DOWN_DAMAGED", MIKEleftDown_Damaged, 4, 6, false);
    int MIKErightDown_Damaged[] = { 4,5,6,7 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightDown_Damaged", "MIKE_DOWN_DAMAGED", MIKErightDown_Damaged, 4, 6, false);
    int MIKEleftUp[] = { 7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftUp", "MIKE_UP", MIKEleftUp, 8, 6, false);
    int MIKErightUp[] = { 8,9,10,11,12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightUp", "MIKE_UP", MIKErightUp, 8, 6, false);
    int MIKEleftGuard[] = { 2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftGuard", "MIKE_GUARD", MIKEleftGuard, 3, 6, false);
    int MIKErightGuard[] = { 3,4,5 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightGuard", "MIKE_GUARD", MIKErightGuard, 3, 6, false);
    int MIKEleftObject_Hang[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftObject_Hang", "MIKE_IDLE", MIKEleftObject_Hang, 4, 6, true);
    int MIKErightObject_Hang[] = { 20,21,22,23 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightObject_Hang", "MIKE_IDLE", MIKErightObject_Hang, 4, 6, true);
    int MIKEleftObject_Attack[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftObject_Attack", "MIKE_OBJECT_ATTACK", MIKEleftObject_Attack, 7, 6, true);
    int MIKErightObject_Attack[] = { 17,18,19,20,21,22,23 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightObject_Attack", "MIKE_OBJECT_ATTACK", MIKErightObject_Attack, 7, 6, true);
    int MIKEleftObject_Throw[] = { 11,10,9,8,7 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleftObject_Throw", "MIKE_OBJECT_ATTACK", MIKEleftObject_Throw, 5, 6, true);
    int MIKErightObject_Throw[] = { 12,13,14,15,16 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKErightObject_Throw", "MIKE_OBJECT_ATTACK", MIKErightObject_Throw, 5, 6, true);
    int MIKEleft_Big_Object_Grab[] = { 4,3 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleft_Big_Object_Grab", "MIKE_OBJECT_GRAB", MIKEleft_Big_Object_Grab, 2, 6, true);
    int MIKEright_Big_Object_Grab[] = { 5,6 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEright_Big_Object_Grab", "MIKE_OBJECT_GRAB", MIKEright_Big_Object_Grab, 2, 6, true);
    int MIKEleft_Small_Object_Grab[] = { 2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEleft_Small_Object_Grab", "MIKE_OBJECT_GRAB", MIKEleft_Small_Object_Grab, 3, 6, true);
    int MIKEright_Small_Object_Grab[] = { 7,8,9 };
    KEYANIMANAGER->addArrayFrameAnimation("MIKEright_Small_Object_Grab", "MIKE_OBJECT_GRAB", MIKEright_Small_Object_Grab, 3, 6, true);
#pragma endregion

    //말콤 애니메이션 저장소
#pragma region MALCOLMANIMATIONS
    int MALCOLMleftIdle[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftIdle", "MALCOLM_IDLE", MALCOLMleftIdle, 4, 6, true);
    int MALCOLMrightIdle[] = { 4,5,6,7 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightIdle", "MALCOLM_IDLE", MALCOLMrightIdle, 4, 6, true);
    int MALCOLMleftWalk[] = { 7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftWalk", "MALCOLM_WALK", MALCOLMleftWalk, 8, 6, true);
    int MALCOLMrightWalk[] = { 8,9,10,11,12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightWalk", "MALCOLM_WALK", MALCOLMrightWalk, 8, 6, true);
    int MALCOLMleftRun[] = { 7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftRun", "MALCOLM_RUN", MALCOLMleftRun, 8, 6, true);
    int MALCOLMrightRun[] = { 8,9,10,11,12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightRun", "MALCOLM_RUN", MALCOLMrightRun, 8, 6, true);
    int MALCOLMleftJump[] = { 12,11,10,9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftJump", "MALCOLM_JUMP", MALCOLMleftJump, 13, 6, true);
    int MALCOLMrightJump[] = { 13,14,15,16,17,18,19,20,21,22,23,24,25 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightJump", "MALCOLM_JUMP", MALCOLMrightJump, 13, 6, true);
    int MALCOLMleftAttack1[] = { 8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftAttack1", "MALCOLM_ATTACK1", MALCOLMleftAttack1, 9, 6, false);
    int MALCOLMrightAttack1[] = { 9,10,11,12,13,14,15,16,17 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightAttack1", "MALCOLM_ATTACK1", MALCOLMrightAttack1, 9, 6, false);
    int MALCOLMleftAttack2[] = { 3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftAttack2", "MALCOLM_ATTACK2", MALCOLMleftAttack2, 4, 6, false);
    int MALCOLMrightAttack2[] = { 4,5,6,7 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightAttack2", "MALCOLM_ATTACK2", MALCOLMrightAttack2, 4, 6, false);
    int MALCOLMleftAttack3[] = { 4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftAttack3", "MALCOLM_ATTACK3", MALCOLMleftAttack3, 5, 6, false);
    int MALCOLMrightAttack3[] = { 5,6,7,8,9 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightAttack3", "MALCOLM_ATTACK3", MALCOLMrightAttack3, 5, 6, false);
    int MALCOLMleftAttack4[] = { 7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftAttack4", "MALCOLM_ATTACK4", MALCOLMleftAttack4, 8, 6, false);
    int MALCOLMrightAttack4[] = { 8,9,10,11,12,13,14,15 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightAttack4", "MALCOLM_ATTACK4", MALCOLMrightAttack4, 8, 6, false);
    int MALCOLMleftDamaged[] = { 6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftDamaged", "MALCOLM_DAMAGED", MALCOLMleftDamaged, 7, 6, false);
    int MALCOLMrightDamaged[] = { 7,8,9,10,11,12,13 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightDamaged", "MALCOLM_DAMAGED", MALCOLMrightDamaged, 7, 6, false);
    int MALCOLMleftDown[] = { 13,12,11,10,9,8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftDown", "MALCOLM_DOWN", MALCOLMleftDown, 14, 6, false);
    int MALCOLMrightDown[] = { 14,15,16,17,18,19,20,21,22,23,24,25,26,27 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightDown", "MALCOLM_DOWN", MALCOLMrightDown, 14, 6, false);
    int MALCOLMleftDown_Damaged[] = { 4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftDown_Damaged", "MALCOLM_DOWN_DAMAGED", MALCOLMleftDown_Damaged, 5, 6, false);
    int MALCOLMrightDown_Damaged[] = { 5,6,7,8,9 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightDown_Damaged", "MALCOLM_DOWN_DAMAGED", MALCOLMrightDown_Damaged, 5, 6, false);
    int MALCOLMleftUp[] = { 8,7,6,5,4,3,2,1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftUp", "MALCOLM_UP", MALCOLMleftUp, 9, 6, false);
    int MALCOLMrightUp[] = { 9,10,11,12,13,14,15,16,17 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightUp", "MALCOLM_UP", MALCOLMrightUp, 9, 6, false);
    int MALCOLMleftGuard[] = { 1,0 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMleftGuard", "MALCOLM_GUARD", MALCOLMleftGuard, 2, 6, false);
    int MALCOLMrightGuard[] = { 2,3 };
    KEYANIMANAGER->addArrayFrameAnimation("MALCOLMrightGuard", "MALCOLM_GUARD", MALCOLMrightGuard, 2, 6, false);
#pragma endregion

  /*_motionName = KEYANIMANAGER->findAnimation("LUKEleftIdle");
    
    KEYANIMANAGER->start("LUKEleftIdle");*/

    

	return S_OK;
}

void EnemyManager::release()
{
}

void EnemyManager::update()
{
    //루크 벡터 업뎃
    for (_viLuke = _vLuke.begin(); _viLuke != _vLuke.end(); ++_viLuke)
    {
        (*_viLuke)->update();
    }
    //마이크 벡터 업뎃
    for (_viMike = _vMike.begin(); _viMike != _vMike.end(); ++_viMike)
    {
        (*_viMike)->update();
    }
    //말콤 벡터 업뎃
    for (_viMalcolm = _vMalcolm.begin(); _viMalcolm != _vMalcolm.end(); ++_viMalcolm)
    {
        (*_viMalcolm)->update();
    }

    KEYANIMANAGER->update();
    
}

void EnemyManager::render()
{
    for (_viLuke = _vLuke.begin(); _viLuke != _vLuke.end(); ++_viLuke)
    {
        RECT temp = (*_viLuke)->GetRect();
        (*_viLuke)->render();
    }
    for (_viMike = _vMike.begin(); _viMike != _vMike.end(); ++_viMike)
    {
        RECT temp = (*_viLuke)->GetRect();
        (*_viMike)->render();
    }
    for (_viMalcolm = _vMalcolm.begin(); _viMalcolm != _vMalcolm.end(); ++_viMalcolm)
    {
        RECT temp = (*_viMalcolm)->GetRect();
        (*_viMalcolm)->render();
    }

}

void EnemyManager::EnemyImageStorage()
{

}

void EnemyManager::SetLuke()
{
    for (int i = 0; i < 10; i++)
    {
        Enemy* luke;
        luke = new Luke;
        luke->SetCamera(_cm);
        luke->init("LUKE_IDLE", "LUKEleftIdle" , PointMake(800 * i + 800, 700));
        _vLuke.push_back(luke);
    }
}

void EnemyManager::SetMike()
{
    for (int i = 0; i < 10; i++)
    {
        Enemy* mike;
        mike = new Mike;
        mike->SetCamera(_cm);
        mike->init("MIKE_IDLE", "MIKEleftIdle", PointMake(800 * i + 1000, 500));
        _vLuke.push_back(mike);
    }
}

void EnemyManager::SetMalcolm()
{
    for (int i = 0; i < 10; i++)
    {
        Enemy* malcolm;
        malcolm = new Malcolm;
        malcolm->SetCamera(_cm);
        malcolm->init("MALCOLM_IDLE", "MALCOLMleftIdle", PointMake(800 * i + 1200, 900));
        _vLuke.push_back(malcolm);
    }
}


