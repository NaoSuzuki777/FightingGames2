#pragma once

using namespace std;


/**
* @author   Suzuki N
* @date     24/07/16
* @note     ���ׂẴR���|�[�l���g�̊��N���X�̒�`�t�@�C��
*/


//myComponent�N���X�������o�ϐ���MyGameObject�N���X���������邽�߂ɑO���錾
class MyGameObject;

/**
 * @class		myComponent
 * @brief		�S�ẴR���|�[�l���g�N���X�̊��N���X
 */
class MyComponent
{
public:
	/*     �����o�ϐ�     */

	/**
	 * @brief		���̃R���|�[�l���g���A�^�b�`����Ă���myGameObject
	 * @History		24/06/17 �쐬(Suzuki N)
	 */
	MyGameObject* gameObject;

	/*     ���\�b�h     */

	/**
	 * @brief		�A�^�b�`����Ă���myGameObject�ɃC���X�^���X��������
	 * @param[in]	myGameObject* _gameObject  �������myGameObject
	 * @date		24/06/17
	 */
	void SetMyGameObject(MyGameObject* _gameObject)
	{
		gameObject = _gameObject;
	}

	/**
	 * @brief		�A�^�b�`����Ă���myGameObject��Ԃ�
	 * @return		�R���|�[�l���g���A�^�b�`����Ă���myGameObject
	 * @date		24/06/17
	 */
	MyGameObject* GetMyGameObject()
	{
		return gameObject;
	}


	/**
	 * @brief		myGameObject�ɃA�^�b�`���ꂽ�u�Ԃɓ���
	 * @ditail		���z�֐�
	 * @date		24/06/17
	 */
	virtual void Start() {}


	/**
	 * @brief		���t���[���Ă΂�郁�\�b�h
	 * @ditail		���z�֐�
	 * @date		24/06/17
	 */
	virtual void Update() {}
};