#pragma once
#include <vector>
#include <memory>
#include "MyComponent.h"


/**
* @author   Suzuki N
* @date     24/07/16
* @note		�R���|�[�l���g���Ǘ�����A���ׂẴI�u�W�F�N�g�����N���X�̒�`
*/


/**
 * @class		MyGameObject
 * @brief       �I�u�W�F�N�g�Ɋւ�������܂Ƃ߂��N���X
 */
class MyGameObject
{
private:
	/*     �����o�ϐ�     */

	/**
	 * @brief		�A�^�b�`����Ă���S�ẴR���|�[�l���g
	 * @History		24/06/17 �쐬(Suzuki N)
	 */
	vector<unique_ptr<MyComponent>> myComponents;


public:
	/**
	 * @brief		�n���h���[��Update���\�b�h�̗D�揇��
	 * @History		24/07/21 �쐬(Suzuki N)
	 */
	int priority;


public:
	/*     ���\�b�h     */


	/**
	 * @brief		�R���X�g���N�^
	 * @author		Suzuki N
	 * @date		24/07/21
	 */
	MyGameObject() : priority(0)
	{
	}


	/**
	 * @brief		�R���|�[�l���g��ǉ�����
	 * @param[in]	�A�^�b�`����R���|�[�l���g
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void AddMyComponent(unique_ptr<MyComponent> _component)
	{
		_component->SetMyGameObject(this);
		//_component->Start();
		myComponents.push_back(move(_component));
	}

	/**
	 * @brief		�w��̃R���|�[�l���g��Ԃ�
	 * @return		�A�^�b�`����Ă����ꍇ�̓C���X�^���X��Ԃ��A����ȊO�Ȃ�nullPtr��Ԃ�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	template<typename T>
	T* GetMyComponent()
	{
		//�e���v���[�g��Type��Component�̔h���N���X�����ׁA������ꍇ�̓R���p�C�����ɃG���[��f��
		static_assert(is_base_of<MyComponent, T>::value, "�R���|�[�l���g�ȊO�̓A�^�b�`�ł��܂���");

		//java��C#�ł����Ƃ����foreach�\��
		for (auto& component : myComponents)
		{
			if (auto* targetComponent = dynamic_cast<T*>(component.get()))
				return targetComponent;
		}

		return nullptr;
	}
};