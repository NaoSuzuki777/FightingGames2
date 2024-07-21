#pragma once


/**
* @author   Suzuki N
* @date     24/07/20
* @note		�ėp�I�ȃN���X�̒�`���܂Ƃ߂��w�b�_�[�t�@�C��
*/


/**
 * @class		Property
 * @brief       ���\�b�h��ʂ��Ēl�̎擾��ύX���s���ׂ̃��b�p�[�N���X
 */
template<typename T>
class Property
{

private:

    /*     �����o�ϐ�     */

    /**
     * @brief   ���b�s���O����ϐ�
     * @History 24/07/20 �쐬(Suzuki N)
     */
    T data;


    /*     ���\�b�h     */

public:

    /**
     * @brief       �R���X�g���N�^
     * @param[in]   T _initial �����l
     * @author		Suzuki N
     * @date		24/07/21
     */
    Property(T _initial) : data(_initial) {}


    /**
     * @brief       �V���ɒl���Z�b�g����
     * @param[in]   T _data �ύX��̒l
     * @author		Suzuki N
     * @date		24/07/21
     */
    void Set(T _data)
    {
        data = _data;
    }


    /**
     * @brief       �l��Ԃ�
     * @return      T data
     * @author		Suzuki N
     * @date		24/07/21
     */
    T Get() { return data; }
};