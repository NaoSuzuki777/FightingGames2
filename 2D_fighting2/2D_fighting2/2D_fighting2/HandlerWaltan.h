#pragma once
#include "MyTransform.h"
#include "MyCollider.h"
#include "MyGameObject.h"


/**
* @author   Suzuki N
* @date     24/07/18
* @note		�����AComponent�̃n���h���[�͂��ׂ�HandlerWaltan�ŌĂяo��
*/


/**
 * @class		HandlerWaltan
 * @brief       ���ׂẴn���h���[���\�b�h�̌Ăяo�����Ǘ�����N���X
 * @detail		�V���O���g���Ő݌v����
 */
class HandlerWaltan
{

    /*     �����o�ϐ�     */

private:

    /**
     * @brief   �C���X�^���X�����ꂽ�I�u�W�F�N�g�S�Ă�ۊǂ��Ă����R���e�i
     * @History 24/07/19 �쐬(Suzuki N)
     */
    vector<MyGameObject*> gameObjects;



 /*     ���\�b�h     */

private:

    /**
     * @brief       �R���X�g���N�^
     * @detail      �O������C���X�^���X�𐶐��o���Ȃ��悤�ɂ��邽�߂̃v���C�x�[�g
     * @author      Suzuki N
     * @date        24/07/19
     */
    HandlerWaltan() {}


public:

    /**
     * @brief       �C���X�^���X���擾����ÓI���\�b�h
     * @detail      ���߂̈�񂾂��C���X�^���X�𐶐�����
     * @author      Suzuki N
     * @date        24/07/19
     */
    static HandlerWaltan& Instance()
    {
        //!�V���O���g���C���X�^���X
        static HandlerWaltan instance;
        return instance;
    }

    //�C���X�^���X�̃R�s�[�֎~
    //�f�t�H���g�̃R�s�[�R���X�g���N�^���폜
    HandlerWaltan(const HandlerWaltan&) = delete;
    //�f�t�H���g�̃R�s�[������Z�q���폜
    HandlerWaltan& operator=(const HandlerWaltan&) = delete;


    /**
     * @brief       �C���X�^���X�����ꂽMyGameObject��ۊǂ��Ă���
     * @detail      MyGameObject�̃R���X�g���N�^�ł̂݌Ă΂��
     * @param[in]   MyGameObject�@�ǉ�����MyGameObject
     * @author      Suzuki N
     * @date        24/07/19
     */
    void AddMyGameObject(MyGameObject* _gameObject)
    {
        gameObjects.push_back(_gameObject);

        cout << gameObjects[0]->priority << "\n";

        _gameObject->priority = -20;

        cout << gameObjects[0]->priority << "\n";
    }
};

