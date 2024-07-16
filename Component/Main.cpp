#include<iostream>
#include<memory>
#include<vector>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;


/**
 * @author		Suzuki N
 * @date		24/06/17
 * @note		�R���|�[�l���g�u���̃T���v���t�@�C��
 * @History		�t�@�C���ɗ����Ȃǂ𖾋L����ꍇ�͂����֏�������
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


//myComponent�N���X�������o�ϐ���GameObject�N���X���������邽�߂ɑO���錾
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



/**
 * @class		myTransform
 * @brief		�I�u�W�F�N�g�̍��W���]�Ȃǂ�ێ�����N���X
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

	/**
	 * @brief		���t���[���Ă΂��
	 * @ditail		�I�[�o�[���C�h�֐�
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void Update() override
	{
		cout << "MyTransform�R���|�[�l���g��Update���\�b�h\n";
	}

	/**
	 * @brief		���[���h���W��Ԃ�
	 * @return		���[���h���W
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	MyVector3 GetPosition() { return Position; }
};



/**
 * @class		
 * @brief		�N���X
 */
class MyCollider : public MyComponent
{

};



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
	/*     ���\�b�h     */


	/**
	 * @brief		�R���|�[�l���g��ǉ�����
	 * @param[in]	�A�^�b�`����R���|�[�l���g
	 * @author		Suzuki N
	 * @date		24/06/17
	 */	
	void AddComponent(unique_ptr<MyComponent> _component)
	{
		_component->SetMyGameObject(this);
		_component->Start();
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
		static_assert(is_base_of<MyComponent, T>::value, "T must derive from Component");

		//java��C#�ł����Ƃ����foreach�\��
		for (auto& component : myComponents)
		{
			if (auto* targetComponent = dynamic_cast<T*>(component.get()))
				return targetComponent;
		}

		return nullptr;
	}

	/**
	 * @brief		�A�^�b�`����Ă���R���|�[�l���g��Update���\�b�h��S�ČĂяo��
	 * @author		Suzuki N
	 * @date		24/06/17
	 */
	void MyComponentsUpdate()
	{
		for (unique_ptr<MyComponent>& component : myComponents)
			component->Update();
	}
};



int main()
{
	unique_ptr<MyGameObject> obj = make_unique<MyGameObject>();

	obj->AddComponent(make_unique<MyTransform>());

	MyTransform* transform = obj->GetMyComponent<MyTransform>();

	cout << "X = " << transform->GetPosition().x << endl;
	cout << "Y = " << transform->GetPosition().y << endl;
	cout << "Z = " << transform->GetPosition().z << endl;

	transform->Position = { -1, -2, -3 };


	cout << "\n\n";

	MyGameObject* obj2 = transform->GetMyGameObject();

	auto gege = obj2->GetMyComponent<MyTransform>();

	cout << "X = " << gege->GetPosition().x << endl;
	cout << "Y = " << gege->GetPosition().y << endl;
	cout << "Z = " << gege->GetPosition().z << endl;

	
	obj->MyComponentsUpdate();


	return 0;
}