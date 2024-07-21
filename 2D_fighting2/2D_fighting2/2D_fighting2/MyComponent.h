#pragma once
#include <functional>
#include "Utilities.h"


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


private:

	/**
	 * @brief		�Փ˔������������ɌĂ΂��R�[���o�b�N�֐�
	 * @History		24/07/19 �쐬(Suzuki N)
	 */
	function<void()> OnCollisionEnterCallBack;

	/**
	 * @brief		�Փ˔��������Ă���ԂɌĂ΂��R�[���o�b�N�֐�
	 * @History		24/07/19 �쐬(Suzuki N)
	 */
	function<void()> OnCollisionStayCallBack;

	/**
	 * @brief		�Փ˔��肪�����ꂽ���ɌĂ΂��R�[���o�b�N�֐�
	 * @History		24/07/19 �쐬(Suzuki N)
	 */
	function<void()> OnCollisionExitCallBack;


public:


	/*     ���\�b�h     */

	/**
	 * @brief		�R���X�g���N�^
	 * @author		Suzuki N
	 * @date		24/07/19
	 */
	MyComponent()
	{
		//�e�R�[���o�b�N�֐��ɃI�[�o�[���C�h���ꂽ���\�b�h��������
		OnCollisionEnterCallBack = bind(&MyComponent::OnCollisionEnter, this);
		OnCollisionStayCallBack = bind(&MyComponent::OnCollisionStay, this);
		OnCollisionExitCallBack = bind(&MyComponent::OnCollisionExit, this);
	}


	/**
	 * @brief		�A�^�b�`����Ă���myGameObject�ɃC���X�^���X��������
	 * @param[in]	myGameObject* _gameObject  �������myGameObject
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void SetMyGameObject(MyGameObject* _gameObject)
	{
		gameObject = _gameObject;
	}

	/**
	 * @brief		�A�^�b�`����Ă���myGameObject��Ԃ�
	 * @return		�R���|�[�l���g���A�^�b�`����Ă���myGameObject
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	MyGameObject* GetMyGameObject()
	{
		return gameObject;
	}

protected:

#pragma region ���z�֐��Q

	/**
	 * @brief		myGameObject�ɃA�^�b�`���ꂽ�u�Ԃɓ���
	 * @detail		���z�֐�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	virtual void Start() {}


	/**
	 * @brief		���t���[���Ă΂�郁�\�b�h
	 * @detail		���z�֐�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	virtual void Update() {}


	/**
	 * @brief		�R���C�_�[�Փˎ��ɓ������\�b�h
	 * @detail		���z�֐�
	 * @author		Suzuki N
	 * @date		24/07/19
	 */
	virtual void OnCollisionEnter() {}


	/**
	 * @brief		�R���C�_�[�Փ˒��ɓ������\�b�h
	 * @detail		���z�֐�
	 * @author		Suzuki N
	 * @date		24/07/19
	 */
	virtual void OnCollisionStay() {}


	/**
	 * @brief		�R���C�_�[�Փ˂��������ɓ������\�b�h
	 * @detail		���z�֐�
	 * @author		Suzuki N
	 * @date		24/07/19
	 */
	virtual void OnCollisionExit() {}

#pragma endregion

	public:

#pragma region �o�^���ꂽ�R�[���o�b�N�֐����Ăԃ��\�b�h�Q

	/**
	 * @brief		�o�^���ꂽ�Փˎ��ɓ������\�b�h�𓭂�����
	 * @author		Suzuki N
	 * @date		24/07/19
	 */
	void OnCollisionEnterHandler()
	{
		if (OnCollisionEnterCallBack)
			OnCollisionEnterCallBack();
	}

#pragma endregion
};
