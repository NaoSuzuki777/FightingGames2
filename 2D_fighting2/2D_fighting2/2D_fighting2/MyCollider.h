#pragma once
#include <iostream>
#include "MyComponent.h"


/**
* @author   Suzuki N
* @date     24/07/18
* @note		�����蔻��̏���ێ�����R���|�[�l���g�̒�`
*/


/**
 * @enum		eColliderType
 * @brief		�R���C�_�[�^�C�v
 */
enum class eColliderType
{
	//!�ʏ�̎l�p�`�^�̂����蔻��(0)
	BoxCollider,
};


/**
 * @class		myTransform
 * @brief		�I�u�W�F�N�g�̍��W���]�Ȃǂ�ێ�����R���|�[�l���g
 */
class MyCollider : public MyComponent
{
private:


public:
	/*     �����o�ϐ�     */

	/**
	 * @brief		�R���C�_�[�^�C�v
	 * @History		24/07/18 �쐬(Suzuki N)
	 */
	eColliderType colliderType;
	


	/*     ���\�b�h     */


	/**
	 * @brief		MyCollider�̃R���X�g���N�^
	 * @detail		�C�j�V�����C�Y�p
	 * @author		Suzuki N
	 * @date		24/07/18
	 */
	MyCollider() : colliderType(eColliderType::BoxCollider)
	{
	}


#pragma region �I�[�o�[���C�h���\�b�h

	/**
	 * @brief		���t���[���Ă΂��
	 * @detail		�I�[�o�[���C�h�֐�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void Start() override
	{
		OnCollisionEnterHandler();
	}


	void OnCollisionEnter() override
	{
		cout << "MyCollider�R���|�[�l���g��OnCollisionEnter���\�b�h\n";
	}

#pragma endregion
};
