#pragma once
#include <iostream>
#include "MyComponent.h"


/**
* @author   Suzuki N
* @date     24/07/16
* @note		���W�n�̏���ێ�����R���|�[�l���g�̒�`
*/


/**
*  @struct		myVector3
*  @brief		3D�x�N�g��
*/
typedef struct
{
	float x;
	float y;
	float z;
}MyVector3;


/**
 * @class		myTransform
 * @brief		�I�u�W�F�N�g�̍��W���]�Ȃǂ�ێ�����R���|�[�l���g
 */
class MyTransform : public MyComponent
{
private:


public:
	/*     �����o�ϐ�     */

	/**
	 * @brief		���[���h���W
	 * @History		24/06/17 �쐬(Suzuki N)
	 */
	MyVector3 Position = { 1,0,0.5 };


	/*     ���\�b�h     */


#pragma region Getter���\�b�h�Q

	/**
	 * @brief		���[���h���W��Ԃ�
	 * @return		���[���h���W
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	MyVector3 GetPosition() { return Position; }

#pragma endregion

#pragma region �I�[�o�[���C�h���\�b�h

	/**
	 * @brief		���t���[���Ă΂��
	 * @detail		�I�[�o�[���C�h�֐�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void Update() override
	{
		cout << "MyTransform�R���|�[�l���g��Update���\�b�h\n";
	}

#pragma endregion
};
